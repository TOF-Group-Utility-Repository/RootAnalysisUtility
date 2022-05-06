//
//  Part of the RootAnalysisUtility package
//
//  Implementation of Graph Utility
//
//  Author              Riccardo Ricci
//  Created             06/05/2022
//  Last modified       06/05/2022
//
//
//
#include "../inc/RAU_Graphs.h"
//
//
TGraphErrors*
uMakeMeTGraphErrors
( TGraph* gTarget ) {
    TGraphErrors* gResult = new TGraphErrors();
    for ( Int_t iPnt = 0; iPnt < gTarget->GetN(); iPnt++ )    {
        Double_t dCurrent_X        =    gTarget->GetPointX(iPnt);
        Double_t dCurrent_Y        =    gTarget->GetPointY(iPnt);
        gResult->SetPoint(iPnt,dCurrent_X,dCurrent_Y);
        gResult->SetPointError(iPnt,0,0);
    }
    return gResult;
}
//
//  --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
//  --- --- --- --- --- --- //! GRAPHS MANIPULATION FUNCTIONS
//  --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
//
//  --- --- --- --- --- --- POINT MANIPULATION FUNCTIONS
//  --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
//
TGraph*
uScale
( TGraph* gTarget, Double_t dScaleX, Double_t dScaleY ) {
    TGraph* gResult = (TGraph*)(gTarget->Clone());
    for ( Int_t iPnt = 0; iPnt < gTarget->GetN(); iPnt++ )    {
        Double_t dCurrent_X        =    gTarget->GetPointX(iPnt);
        Double_t dCurrent_Y        =    gTarget->GetPointY(iPnt);
        gTarget->SetPoint(iPnt,dScaleX*dCurrent_X,dScaleY*dCurrent_Y);
    }
    return gResult;
}
//
TGraphErrors*
uScale
( TGraphErrors* gTarget, Double_t dScaleX, Double_t dScaleY ) {
    TGraphErrors* gResult = (TGraphErrors*)(gTarget->Clone());
    for ( Int_t iPnt = 0; iPnt < gTarget->GetN(); iPnt++ )    {
        Double_t dCurrent_X        =    gTarget->GetPointX(iPnt);
        Double_t dCurrent_Y        =    gTarget->GetPointY(iPnt);
        Double_t dCurrent_eX       =    gTarget->GetErrorX(iPnt);
        Double_t dCurrent_eY       =    gTarget->GetErrorY(iPnt);
        gTarget->SetPoint       ( iPnt, dScaleX*dCurrent_X,     dScaleY*dCurrent_Y  );
        gTarget->SetPointError  ( iPnt, dScaleX*dCurrent_eX,    dScaleY*dCurrent_eY );
    }
    return gResult;
}
//
TGraph*
uMovingAverage
( TGraph* gTarget, Int_t nPoints ) {
    TGraph* gResult = new TGraph();
    for ( Int_t iPnt = 0; iPnt < gTarget->GetN() - nPoints; iPnt++ )    {
    Double_t    dMeanXVal   =   0;
    Double_t    dMeanYVal   =   0;
        for ( Int_t jPnt = 0; jPnt < nPoints; jPnt++ )    {
            dMeanXVal   +=  gTarget->GetPointX(iPnt+jPnt);
            dMeanYVal   +=  gTarget->GetPointY(iPnt+jPnt);
        }
        Int_t   iCurrent_Point  = gResult->GetN();
        gResult->SetPoint       ( iCurrent_Point, dMeanXVal/nPoints, dMeanYVal/nPoints );
    }
    return gResult;
}
//
TGraphErrors*
uMovingAverage
( TGraphErrors* gTarget, Int_t nPoints ) {
    TGraphErrors* gResult = new TGraphErrors();
    for ( Int_t iPnt = 0; iPnt < gTarget->GetN() - nPoints +1; iPnt++ )    {
        Double_t    dMeanXVal   =   0;
        Double_t    dMeanYVal   =   0;
        Double_t    dMeanXErr   =   0;
        Double_t    dMeanYErr   =   0;
        for ( Int_t jPnt = 0; jPnt < nPoints; jPnt++ )    {
            dMeanXVal   +=  gTarget->GetPointX(iPnt+jPnt);
            dMeanYVal   +=  gTarget->GetPointY(iPnt+jPnt);
            dMeanXVal   +=  gTarget->GetErrorX(iPnt+jPnt)*gTarget->GetErrorX(iPnt+jPnt);
            dMeanYVal   +=  gTarget->GetErrorY(iPnt+jPnt)*gTarget->GetErrorY(iPnt+jPnt);
        }
        Int_t   iCurrent_Point  = gResult->GetN();
        gResult->SetPoint       ( iCurrent_Point, dMeanXVal/nPoints, dMeanYVal/nPoints );
        gResult->SetPointError  ( iCurrent_Point, sqrt(dMeanXVal)/nPoints, sqrt(dMeanYVal)/nPoints );
    }
    return gResult;
}

//  --- --- --- --- --- --- DIFFERENTIAL FUNCTIONS
//  --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
//
TGraphErrors*
uDerivative
 ( TGraphErrors* gTarget ) {
    TGraphErrors* gResult = new TGraphErrors();
    Double_t    dMeanXVal   =   0;
    Double_t    dDervYVal   =   0;
    Double_t    dMeanXErr   =   0;
    Double_t    dDervYErr   =   0;
    for ( Int_t iPnt = 0; iPnt < gTarget->GetN() - 1; iPnt++ )    {
        auto kFirst_PointX  = gTarget->GetPointX(iPnt);
        auto kSecondPointX  = gTarget->GetPointX(iPnt+1);
        auto kFirst_PointY  = gTarget->GetPointY(iPnt);
        auto kSecondPointY  = gTarget->GetPointY(iPnt+1);
        auto kFirst_ErrorX  = gTarget->GetErrorX(iPnt);
        auto kSecondErrorX  = gTarget->GetErrorX(iPnt+1);
        auto kFirst_ErrorY  = gTarget->GetErrorY(iPnt);
        auto kSecondErrorY  = gTarget->GetErrorY(iPnt+1);
        dMeanXVal   =   0.5*( kFirst_PointX + kSecondPointX );
        dMeanXErr   =   0.5*uSquareSum( { kFirst_ErrorX, kSecondErrorX } );
        dDervYVal   =   ( kSecondPointY - kFirst_PointY )/( kSecondPointX - kFirst_PointX );
        dDervYErr   =   dDervYVal*uSquareSum( { uSquareSum( { kFirst_ErrorX, kSecondErrorX } )/( kSecondPointX - kFirst_PointX ), uSquareSum( { kFirst_ErrorY, kSecondErrorY } )/( kSecondPointY - kFirst_PointY ) } );
        Int_t   iCurrent_Point  = gResult->GetN();
        gResult->SetPoint       ( iCurrent_Point, dMeanXVal, dDervYVal );
        gResult->SetPointError  ( iCurrent_Point, sqrt(dMeanXVal), sqrt(dDervYErr) );
    }
    return gResult;
}

