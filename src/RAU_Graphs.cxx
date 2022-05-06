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