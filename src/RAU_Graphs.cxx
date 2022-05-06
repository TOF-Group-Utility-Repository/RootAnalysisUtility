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
// #include "../inc/RAU_Graphs.h"
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