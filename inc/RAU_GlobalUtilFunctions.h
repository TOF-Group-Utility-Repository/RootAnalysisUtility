//
//  Part of the BolognaLaboratoryUtility package
//
//  Global Functions
//
//  Author              Riccardo
//  Created             06/05/2022
//  Last modified       06/05/2022
//
//
#ifndef RAU_GLOBALUTILFUNCTIONS_H
#define RAU_GLOBALUTILFUNCTIONS_H
//
//  --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
//  --- --- --- --- --- --- //! GENERAL UTILITY FUNCTIONS
//  --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
//
template    <   typename TTarget  >
int
sgn( TTarget uTarget )    { return ( TTarget(0) < uTarget ) - ( uTarget < TTarget(0) ); }
//
Double_t
uSquareSum
 ( std::initializer_list<Double_t> list )  {
    Double_t    fResult =   0;
    for ( auto element : list ) fResult +=  element*element;
    return  TMath::Sqrt(fResult);
}
//
//  --- --- --- --- --- --- /
//  --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
//
#endif
