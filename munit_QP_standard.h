#include <string>       // std::string
#include <iostream>     // std::cout
#include <iomanip>      // cout manipulators?
#include <sstream>      // std::stringstream, std::stringbuf

#include <QDebug>
#include <cmath>
#include <limits>
#include <stdio.h>
#include <QCoreApplication>
using namespace std;


map <string, string> munit_unit_map;
stringstream schTream;

void errorqq (string error_message)
{
	cout << error_message << endl;                                  // There has to be a better way to throw an exception.
	int treh = 44 / 0;  // throw std::runtime_error(err_message);   // But for debugging purposes, it will do.
}

const double pi = 2.0 * acos(0);
double piasdfasf = pi;

#include "munit_trying.h"

munit_quantity jqday(FUNDAMENTAL, 1, 86400);
munit_place munit_date_base(jqday, true);

#include "Date_Arithmetic.h"
#include "Date_Arithmetic_Interface.h"




int main(int argc, char *argv[])
{

#include "munit_preliminaries.h"    // The user must never edit this file.
                                    // The trigononetric functions depend on the values therein.



#include "munit_vectordefs.h"       // The user should feel free to edit this file.
                                    // It contains the definitions of the units of measure.

QCoreApplication aothello(argc, argv);

#include "days_and_months.h"
string RAW_Month_Names[25];         // Put in the month names. The list of 12 has to be copied four times.
string FADJ_Month_Names[25];
{
    for (int ix = 0; ix < 25; ix++)
        FADJ_Month_Names[ix] =   RAW_Month_Names[ix] = "haha";

    int ixs = 12; int ix;
    for (ix = 0; ix < 12; ++ix) {RAW_Month_Names[ix]  = RAW_Month_Names[ixs]   = the_month_names[ix]; ++ixs;}

        ixs = 2;
    for (ix = 0; ix < 22; ++ix) {FADJ_Month_Names[ix] = RAW_Month_Names[ixs];                         ++ixs;}
                                 FADJ_Month_Names[22] = RAW_Month_Names[0];
                                 FADJ_Month_Names[23] = RAW_Month_Names[1];
}

// The curly braces in lines 53 and 64 are just meant to limit the scope of some variables,
// not for any control of branching or looping.
