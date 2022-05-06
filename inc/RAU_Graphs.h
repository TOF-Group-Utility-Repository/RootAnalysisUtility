//
//  Part of the RootAnalysisUtility package
//
//  Graphs Utility
//
//  Author              Riccardo Ricci
//  Created             06/05/2022
//  Last modified       06/05/2022
//
#ifndef RAU_GRAPHS_H
#define RAU_GRAPHS_H
//
//  --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
//  --- --- --- --- --- --- //! GENERAL UTILITY VARIABLES
//  --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
//
//
//  --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
//  --- --- --- --- --- --- //! GENERAL UTILITY FUNCTIONS
//  --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
//
TGraphErrors*
uMakeMeTGraphErrors ( TGraph* gTarget );
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
( TGraph* gTarget, Double_t dScaleX, Double_t dScaleY );
//
//
template<   typename TTarget >
TTarget* uInvertX    ( TTarget* gTarget );
//
template<   typename TTarget >
TTarget* uInvertY    ( TTarget* gTarget );
//
template<   typename TTarget >
TTarget* uInvertXY   ( TTarget* gTarget );
//
TGraph*
uMovingAverage
( TGraph* gTarget, Int_t nPoints );
#endif