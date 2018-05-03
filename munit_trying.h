#define N_FUNDAMENTALS 6                /* You, the user, might need to change this value, in accordance with the customization instructions in the vectordefs.h file.
                                           You  must never change any other line or anything else in this file.

---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  - -   ---  -  ---  --   ---  -  ---  --   ---  -

The following two statements should be st the top of every #included file, the very first two lines, in order to make sure that the file is #included once and only once.
                                        Make sure that there is a #endif at the end of the file.

                        The exception here is to call attention to the one line in this file that the user might have to change.

                                                                                                                                                                        */
#ifndef KADIDDLIDIP_FUZKEP
#define KADIDDLIDIP_FUZKEP              // The name in these two lines is just random letters -- not repeated ever again. Just make sure it's the same in both lines.
                                                                                                                                                                        /*
---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -
                                                                                                                                                                        */
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

                                                                                                                                                                        /*
Some constants that are needed for declarations ... Should they, instead be assigned with const, as is pi below? Maybe.
                                                                                                                                                                        */
#define LEN_SHORT_INT 2                 // Length of a double short integer.         On all the Intel-compatible machines it's two..
#define LEN_DOUBLE 8                    // length of a double floating point number. On all the Intel-compatible machines it's eight.
#define LEN_DOUBLE_M1 7                 // ABOVE LENGTH - 1
#define N_FUNDA_DOUBLE_M1  13           // N_FUNDAMENTALS + LEN_DOUBLE_M1
                                                                                                                                                                        /*

The following rEL_DEFAULT valus is used as nothing but a default value. The syntax simply doesn't allow "not specified", so an arbitrary value is needed.
                                           This arbitrary value is just random digits and is never referenced.
                                                                                                                                                                        */
#define rEL_DEFAULT	8.589194854320E57   // This is a default value which tells the munit_quantity constructor to set the object's qcontent value to 1.

                                                                                                                                                                        /*
The following four constants are used as values for the first parameter in the munit_quantity class constructor. The labels are referenced, but the never are.
Maybe they should be defined in an enum instead.
                                                                                                                                                                        */

#define FUNDAMENTAL 0x788001            // In the constructor, all the arr_members are made zero, except for the one specified. This is for fundamental units of measure.

#define ZERONIC 0x788721                // In the constructor, all the arr_members are made zero. In other words, it's "zeronic". (Excuse me for making up a new word, but I think it's descriptive.)

#define SAMPLE 0x79529e                 // The constructor generates a sample -- nothing useful for any application, but it was useful in debugging this munit_trying file.


#define GARBAGE_STAY 0x795721           /* The munit_quantity constructor allocates the space for a munit_quantity object but does nothing more.
                                           Whatever garbage is in that allocated storage simply says there.

                                           This satisfies the need for a default constructor. But it  also  serves  another  purose:  to  allow
                                           a construct like munit_quantity my_weight = 190 * lbs, in what co -- central to the whole idea of this package.; .

                                           In C++ a class object is supposed to behave like a value. In the above construct it looks like it does. But actually,
                                           the first object (in this case my_weight) is constructed with the default constructor. Other things happen, then the
                                           operator= is executed. 
																																										/*
The following three constants are different from the above, in that the values *are* imortant.

const double pi = 2.0 * acos(0.0);										// Archimedes' constant pi = 3.1415926 ... used in the trigonometric functions					*/
const double trig_conversion_factor = 648000.0 / pi;					/* a conversion factor used in converting angle units: radians, degrees and gradients
const munit_quantity G_Acc = 980.665 * cm/(time_second * time_second);  // gravitational acceleration constant , used in converting mass measurement to force measurement


Now, two lines used in split_measure.h																																	*/
#define splitting return split_string_unit(readout_subject.qcontent / unit_subject.qcontent, d_significant,
#define end_splitting ); break
																																										/*
---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -

two declarations that relate to the reading out of the munit_quantity declared in munit_QP_standard.h
                                                                                                                                                                        */
//    map <string, string> munit_unit_map;
//    stringstream schTream;

string toozies;
string xstringup_carrier;
string PLaqemines   = "PL";
string sprintf_NumGeneral = "%'0.*lG";

#define NADA
#define PUTIN_PL "\"PL\""
#define quovink(oqv, oyz) xstringup_carrier = oqv.stringup(); munit_unit_map[xstringup_carrier] = #oyz; toozies = #oyz
#define quovinkPL(oqv, oyz, oqyplin) xstringup_carrier = oqv.stringup() + PLaqemines; munit_unit_map[xstringup_carrier] = #oyz; toozies = #oyz
                                                                                                                                                                        /*
---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -

The following construct is for something that will be used in the MACHINE-DEPENDENT routine to put a munit_quantity object in a string that can be put in a map.
in a map, where it can be looked up later. When the fundamental and derived units are declared in the munit_vectordefs file, they are inserted in the map. When
they are read out, the unit's qcontent and arr_members vector are looked up.

In the floating-point numbers on the Intel-compable machines, the least significant part comes first; and the most signicant part comes last.
This makes the stringup() routine somewhat complicated.
                                                                                                                                                                        */

    union double_to_be_torn                                  // used in the routine where a floating point number is part of a sort/lookup key ...
    {                                                        // The most significant part has to come first.
        double double_intact;
        char pieces_torn_off[LEN_DOUBLE];
    };

    union shortint_to_be_torn                                // used in the routine where a short integer is found, that is used in a switch statement.
    {                                                        // which bits and bytes of the short integer are most signigicant is immaterial.
        short short_char_string;
        char pieces_that_were_quovinked_in[LEN_SHORT_INT];   //
    };


    string split_string_unit(double, int, int, ...);         // split a readout unit, e.g. 17 feet 5 inches

                                                                                                                                                                        /*
---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  

Now the class declaration and the private members
																																										*/ 
class munit_quantity
{
	friend class yrmo_date;
    friend class munit_place;

  private:                                                                  // private members
	short arr_members[N_FUNDAMENTALS];
	double qcontent;

  public:                                                                     // public declaration
                                                                                                                                                                        /*
---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -

Now comes the constructor. Notice how the above- #defined constants determine what kind of munit_quantity object is defined.

                                                                                                                                                                        */
        munit_quantity(int xin = GARBAGE_STAY, int bwarvom = 0, double bwarqin = rEL_DEFAULT)

        {
            if (xin == GARBAGE_STAY)  { }                                         // Allocate the stape for the munit_quantity object. And let the garbage stay.
            else                                                                  // In the construct it's meant for, that space will be filled right away, e.g. my_weight = 190 * lbs
            {
                qcontent = (bwarqin == rEL_DEFAULT) ? 1.0 : bwarqin;              // If you aren't going to let the garbage stay, then the
                                                                                  // qcontent has to be set.

                if (xin == SAMPLE) {                                              // A sample is generated.
                    int xink = bwarvom;                                           // This is meant for debugging this file -- not for ay real world applications.
                    for (int ivk = (N_FUNDAMENTALS - 1); ivk >= 0; --ivk)
                            { arr_members[ivk] = xink % 10; xink /= 10;	}
                         }
                else
                {
                    for (int ivk = 0; ivk != N_FUNDAMENTALS; ++ivk)               // Make a zero vector, either for ZERONIC or for a FUNDAMENTAL unit.
                                                arr_members[ivk] = 0;
                    if (xin == ZERONIC) { }                                       // ZERONIC means "leave the arr-members all zeroes."

                    else                { arr_members[bwarvom] = 1; }             // FUNDAMENTAL unit. Notice that electric charge is a fundamental unit.
                }                                                                 //                   and current = electric charge / time. -- and hence not a fundamental unit.
             }
        }
                                                                                                                                                               /*
---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -

        vector multiplication and division                                  // e.g.  force = mass * acceleration,  and  velocity = distance / time
        */


        munit_quantity operator*(munit_quantity arr2)					    // multiplication
		{
			munit_quantity shrt_temp;

			for (int ivk = 0; ivk != N_FUNDAMENTALS; ++ivk) shrt_temp.arr_members[ivk] = 
												this->arr_members[ivk] + arr2.arr_members[ivk];

			shrt_temp.qcontent = this->qcontent * arr2.qcontent;

			return shrt_temp;
		}

        munit_quantity operator/(munit_quantity arr2)						// division
		{
			munit_quantity shrt_temp;

            for (int ivk = 0; ivk != N_FUNDAMENTALS; ++ivk) shrt_temp.arr_members[ivk] = this->arr_members[ivk] - arr2.arr_members[ivk];

			shrt_temp.qcontent = this->qcontent / arr2.qcontent;

			return shrt_temp;
		}
                                                                            // compound assignments of vector multiplication and division

		void operator*=(munit_quantity arr2) { qcontent *= arr2.qcontent;
				for (int ivk = 0; ivk != N_FUNDAMENTALS; ++ivk) arr_members[ivk] += arr2.arr_members[ivk]; }
				
		void operator/=(munit_quantity arr2) { qcontent /= arr2.qcontent;
				for (int ivk = 0; ivk != N_FUNDAMENTALS; ++ivk) arr_members[ivk] -= arr2.arr_members[ivk]; }
        /*

---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -

        scalar mutiplication and division                                   // e.g. airplane_speeed = mach * 2.04  or  bag_contents = lbs / 4  (i.e. a quarter of a pound)
                                                                                                                                                                           */

        munit_quantity operator*(double xfactor)						    // multiplication
		{
			munit_quantity shrt_temp;

			for (int ivk = 0; ivk != N_FUNDAMENTALS; ++ivk) shrt_temp.arr_members[ivk] = this->arr_members[ivk];
			shrt_temp.qcontent = this->qcontent * xfactor;

			return shrt_temp;
		}

        munit_quantity operator/(double xfactor)							// division
		{
			munit_quantity shrt_temp;

			for (int ivk = 0; ivk != N_FUNDAMENTALS; ++ivk) shrt_temp.arr_members[ivk] = this->arr_members[ivk];
			shrt_temp.qcontent = this->qcontent / xfactor;

			return shrt_temp;
		}

        void operator*=(double xfactor) { qcontent *= xfactor; }            // compound assignments of scalar multiplication and division                                                                                                                                                                      /*
        void operator/=(double xfactor) { qcontent /= xfactor; }
                                                                                                                                                                       /*
--- -- --- ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  --

miscellaneous functions


first, a comparing function, needed by operator+ and operator- , to prevent the addition and subtraction of unlike quantities, e.g. 21 hours + 3 kilograms.
       while we're at it, see if one is greater than the other.                                                                e.g. 5 hours > 3 hours.


                                                                                                                                                                       */
        int munit_howlike(munit_quantity muni2)                             // How much alike are two munit quaneities?
                                                                            // answer returned: 3 = completely unalike,         e.g. 21 hours and 3 kilograms
        {                                                                   //                  2 = first >  second             e.g.  5 hours > 3 hours.
                                                                            //                  1 = first <  second             e.g.  2 hours < 3 hours
                                                                            //                  0 = first == second             3.g.  2 hours = 2 hours


                                                                            // Now a word about the unorthodox looping method used in this routine.
            int ivk = 0;                                                    // It uses a goto but it avoids having to do a second compare after the loop's end.
            voqthhetvb_ogb:                                                 //
                if (this->arr_members[ivk] != muni2.arr_members[ivk])       // An unequal compare has been found.
                                                            return 3;       //
                                                                            //
                if (++ivk < N_FUNDAMENTALS)  goto voqthhetvb_ogb;           // The loop reached the end with no unequal compare being found.

            //  This statement label is random letters with no meaning.
            //  That doesn't matter, because it's not referenced anywhere   // If this were a "while" or "for", then the closing brace would be here.
            //                                                       else.  // And with a "break" instead of the "return 3" we'd have to test how we got here.


//         Now that we know, that the two are not unalike, we could just end the function and return. But while we're at it, we might as well see which quantity is greater.


            int zhomma = this->qcontent - muni2.qcontent;
            if (zhomma > 0)                             return 2;
            if (zhomma < 0)                             return 1;           // This is straight-forward.
            else                                        return 0;
        }
                                                                                                                                                                        /*

The following function is a special case of he above.
It is necessary because it's used by the trigonometric functions before the "angle" unit is defined, in the vectordefs file.                                            */

        bool is_Angle()
        {
            if (this->arr_members[0] != 1) return false;
            int ivk = 1;
                voqthhetvb_ogbey:
                    if (this->arr_members[ivk] != 0) return false;          // This is straight-forward like the above.
                    if (++ivk < N_FUNDAMENTALS)  goto voqthhetvb_ogbey;
                                                     return true;
        }
																																										/*
And another variation on the above function -- to find out if a function is ZERONIC, i.e. if all the arr_members are zero
																																										*/
		bool is_ZERONIC()
		{
			if (this->arr_members[0] != 0) return false;
			int ivk = 0;
				voqthhetvb_ogbey_ZERONIC:
					if (this->arr_members[ivk] != 0) return false;          // This is straight-forward like the above.
					if (++ivk < N_FUNDAMENTALS)  goto voqthhetvb_ogbey_ZERONIC;
													 return true;
		}

        string stringup()
        {
            string rack("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", N_FUNDA_DOUBLE_M1); // the string that will be returned. This initialization is just to allocate the space.
                                                                                                //     Let's assume that this N_FUNDA_DOUBLE_M1 <= 52, by a good margin.
            double_to_be_torn tearing_qcontent;

            int ivk;
            for (ivk = 0; ivk != N_FUNDAMENTALS; ++ivk) rack[ivk] = arr_members[ivk];           // First part of the return string is the unit-type vector

            tearing_qcontent.double_intact = qcontent;                                          // Second part is the qcontent, with an adjustment made.
            int ivok = LEN_DOUBLE_M1;

            while (ivk != N_FUNDA_DOUBLE_M1)
            {
                rack[ivk] = tearing_qcontent.pieces_torn_off[ivok]; ++ivk; --ivok;              // Each place on the rack (return string) gets a piece of the qcontent.
            }                                                                                   // a piece torn off, you might say
                                                                                                //
                                                                                                // Leave off the least significant byte of the qcontent. Allow for round-off error.
            return rack;
        }
                                                                                                                                                                      /*
        ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --

                                            Addition and subtraction
                                                                                                                                                                       */

        munit_quantity operator+(munit_quantity muni3)
        {
            munit_quantity shrt_temp;
            string err_msg = "error in addition, unlike quantities";
            if (munit_howlike(muni3) == 3) errorqq(err_msg);

            for (int ivk = 0; ivk != N_FUNDAMENTALS; ++ivk) shrt_temp.arr_members[ivk] = muni3.arr_members[ivk];

            shrt_temp.qcontent = this->qcontent + muni3.qcontent;
            return shrt_temp;
        }

        munit_quantity operator-(munit_quantity muni3)
        {
            munit_quantity shrt_temp;
            string err_msg = "error in subtraction, unlike quantities";
            if (munit_howlike(muni3) == 3) errorqq(err_msg);

            for (int ivk = 0; ivk != N_FUNDAMENTALS; ++ivk) shrt_temp.arr_members[ivk] = muni3.arr_members[ivk];


            shrt_temp.qcontent = this->qcontent - muni3.qcontent;
            return shrt_temp;
        }

		double scalar_get() { if (!is_ZERONIC()) errorqq("Only ZERONIC quantities can be converted to scalar"); return qcontent; }
                                                                                                                                                                       /*
---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -

                                            Friends and the end of the clss declaration

                                                                                                                                                                       */
        friend munit_quantity operator*(double, munit_quantity);            // Allow for a construct like (178 * lbs) instead of (lbs * 178).
        friend int munit_compare(munit_quantity, munit_quantity);           // Allow for a contrtuct like munit_compare(q1, q2) instead of q1.munit_compare(q2).
        friend string munit_readout(munit_quantity, munit_quantity, int, string, double);

        friend double sin(munit_quantity);
        friend double cos(munit_quantity);
        friend double tan(munit_quantity);
        friend double cot(munit_quantity);
        friend double csc(munit_quantity);
        friend double sec(munit_quantity);

        friend munit_quantity Asin(double);
        friend munit_quantity Acos(double);
        friend munit_quantity Atan(double);
        friend munit_quantity Acot(double);
        friend munit_quantity Asec(double);
        friend munit_quantity Acsc(double);
};
/*     ---- -- --- ---- -- --- ---- -- --- ---- -- --- ---- -- --- ---- -- --- ---- -- --- ---- -- --- ---- -- --- ----
-- --- ---- -- --- ---- -- --- ---- -- --- ---- -- --- ---- -- --- ---- -- --- ---- -- --- ---- -- --- ---- -- --- ----
																																																				 */ 
        munit_quantity operator*(double xifactor, munit_quantity muni2)  { return muni2 * xifactor; }
        int munit_compare(munit_quantity muni1,   munit_quantity muni3) { return muni1.munit_howlike(muni3); }


        string munit_readout(munit_quantity readout_subject, munit_quantity unit_subject, int d_significant = 6, string PL_addon = "", double PL_shift = 0.0)													 /*

			purpose: to format the number readout_subject.qcontent / unit_subject.qcontent
		
			1. If the munit_quantity object is not compatible with the units to be converted, abort with an error..
			2. Decide the type of format, e.g. 67 inches or 5 feet 7 inches.
			3. Do the formatting.
																																																				 */																																												
        {  
            char munit_readout_place[50];
            if (munit_compare(readout_subject, unit_subject) == 3) errorqq("readout the wrong kind of unit");
                                                                                                // Step 1 -- Compatibility

            string findrack = unit_subject.stringup() + PL_addon;                           	// Step 2 -- The formatting instructions should be in the munit_unit_map.
																								//			 If so,  they were put in with the quovink or quovini statements.

            string skeleton = munit_unit_map[findrack];
            if (skeleton == "") errorqq("not declared a valid unit -- not quovinked in");

																								//			 If not, then abort.
			if (('0' <= skeleton[0]) && (skeleton[0] <= '9'))
            {
                switch (atoi(skeleton.c_str()))                                                 // Step 3 -- Do the split form of formatting, e.g. 5 feet 7 inches.
                {
#include "split_measure.h"
                default:
                    errorqq("special readout type needs to be put in");							// 			 Forgot to put in the split specification.
                    return "haha";
                }
            }
            else
            {

                    schTream.str("");
                    schTream << setw(2) << setprecision(d_significant) << ((readout_subject.qcontent - PL_shift) / unit_subject.qcontent) << " " << skeleton;
                    return schTream.str();
            }
       }


        string split_string_unit(double subject, int last_presision, int nstrings, ...)
        {
            string stralola; // for debugging only
            va_list vlatl;
            va_start(vlatl, nstrings);
            int nlimits = nstrings - 2;

            string s_labels[nstrings]; int s_limits[nlimits];  int s_returns[nlimits]; double ds_return, dsx; int ibucket, ix, s_limit;
            //                                                 In the pseudo-code below, ds_return  functions like s_returns[nlimits].

            int ivk;
            for (ivk = 0; ivk < nstrings; ++ivk) { s_labels[ivk]  = va_arg(vlatl, char *); } // read in the parameters
            for (ivk = 0; ivk < nlimits;  ++ivk) { s_limits[ivk]  = va_arg(vlatl, int)   ; }

                                                                                                                                                                                            /*

            ibucket = subject; s_limits[-1] = a large number;

            for (int ivk = mlimits; ivk >= 0; --ivk;) { s_returns[ivk] = mod(ibucket, s_limits[ivk - 1]); ibucket /= s_limits[ivk - 1]; }



            These two lines are pseudo-code, of course, and wouldn't compile, for obvious reasons:

                                                                              1: You can't have a subscropt of -1.

                                                                              2: The s_returns[nlimits] is floating point and has to be calulated as such.

                                                                              Thereefore, the first and last iterations of this loop have to be singled out.

                                                                                                                                                                                            */
            int n1limits = nlimits - 1;  ivk = n1limits;
            if (ivk < 0) ds_return = subject;                                                // If there are only one or two s_labels, then there aren't any n_limits,
            else                                                                             // The subject, in that case goes into the return string, with the s_labels before and after.
            {
                ds_return = s_limits[ivk]; ds_return *= modf(subject / ds_return, &dsx);     // This is the first iteration of the above pseudo-code.
                ibucket = (int) dsx;                                                         // Once again, s_returns[nlimits] is called ds_return (singular).

                while (ivk > 0)
                {
                    s_limit = s_limits[ivk - 1];                                             // s_limit = singular of s_limits[ivk - 1]
                    ix = ibucket; ibucket /= s_limit;                                        // s_returns[ivk] = mod(ibucket, s_limit]; ibucket = int(ibucket / s_limit;
                    s_returns[ivk] = ix - ibucket * s_limit;                                 // This is the iterations of the above pseudo-code, apart from the first and last.
                --ivk;}

                s_returns[0] = ibucket;                                                      // This is the last iteration of the obove pseudo-code -- the only information needed.
            }
                                                                                                                                                                                                                 /*


            Now, string up the labels with the nreturns calculated.
                                                                                                                                                                                                                 */
            schTream.str("");
            schTream << s_labels[0];                                                         // Clear out the string stream before stringing the s_returns.

                for (ivk = 0; ivk < nlimits; ++ivk)
                {
                    if (s_returns[ivk] != 0) schTream << s_returns[ivk] << s_labels[ivk + 1];// Include only the non-zero s_returns in the return strings.
                }

            if (ds_return != 0.0) schTream << setprecision(last_presision) << ds_return << s_labels[nstrings - 1];
                                                                                             // and of course the final ds_return if it's non-zero
            stralola = schTream.str();
            return schTream.str();
        }
																																																				 /*
        and now the trigonometric functions
																																																				 */
        double sin(munit_quantity muni11) { if (!muni11.is_Angle())
                                               errorqq("sine of a non-angle");       return       sin(muni11.qcontent / trig_conversion_factor); }

        double cos(munit_quantity muni11) { if (!muni11.is_Angle())
                                               errorqq("cosine of a non-angle");     return       cos(muni11.qcontent / trig_conversion_factor); }

        double tan(munit_quantity muni11) { if (!muni11.is_Angle())
                                               errorqq("tangent of a non-angle");    return       tan(muni11.qcontent / trig_conversion_factor); }

        double cot(munit_quantity muni11) { if (!muni11.is_Angle())
                                               errorqq("co-tangent of a non-angle"); return 1.0 / tan(muni11.qcontent / trig_conversion_factor); }

        double csc(munit_quantity muni11) { if (!muni11.is_Angle())
                                               errorqq("co-secant of a non-angle");  return 1.0 / sin(muni11.qcontent / trig_conversion_factor); }

        double sec(munit_quantity muni11) { if (!muni11.is_Angle())
                                               errorqq("secant of a non-angle");     return 1.0 / cos(muni11.qcontent / trig_conversion_factor); }

																																																				 /*
        and now the invese tragonometric functions.  Notice the capital "A" in the function names.
																																																				 */

        munit_quantity Asin(double muni21)
        {
            munit_quantity shrt_temp;
            shrt_temp.arr_members[0] = 1; for (int ivk = 1; ivk != N_FUNDAMENTALS; ++ivk) shrt_temp.arr_members[ivk] = 0; // Make the munit_quantity an angle.
            shrt_temp.qcontent = trig_conversion_factor * asin(muni21);
            return shrt_temp;
        }

        munit_quantity Acos(double muni21)
        {
            munit_quantity shrt_temp;
            shrt_temp.arr_members[0] = 1; for (int ivk = 1; ivk != N_FUNDAMENTALS; ++ivk) shrt_temp.arr_members[ivk] = 0; // Make the munit_quantity an angle.
            shrt_temp.qcontent = trig_conversion_factor * acos(muni21);
            return shrt_temp;
        }

        munit_quantity Atan(double muni21)
        {
            munit_quantity shrt_temp;
            shrt_temp.arr_members[0] = 1; for (int ivk = 1; ivk != N_FUNDAMENTALS; ++ivk) shrt_temp.arr_members[ivk] = 0; // Make the munit_quantity an angle.
            shrt_temp.qcontent = trig_conversion_factor * atan(muni21);
            return shrt_temp;
        }

        munit_quantity Acot(double muni21)
        {
            munit_quantity shrt_temp;
            shrt_temp.arr_members[0] = 1; for (int ivk = 1; ivk != N_FUNDAMENTALS; ++ivk) shrt_temp.arr_members[ivk] = 0; // Make the munit_quantity an angle.
            shrt_temp.qcontent = trig_conversion_factor * atan(1.0 / muni21);
            return shrt_temp;
        }

        munit_quantity Acsc(double muni21)
        {
            munit_quantity shrt_temp;
            shrt_temp.arr_members[0] = 1; for (int ivk = 1; ivk != N_FUNDAMENTALS; ++ivk) shrt_temp.arr_members[ivk] = 0; // Make the munit_quantity an angle.
            shrt_temp.qcontent = trig_conversion_factor * asin(1.0 / muni21);
            return shrt_temp;
        }

        munit_quantity Asec(double muni21)
        {
            munit_quantity shrt_temp;
            shrt_temp.arr_members[0] = 1; for (int ivk = 1; ivk != N_FUNDAMENTALS; ++ivk) shrt_temp.arr_members[ivk] = 0; // Make the munit_quantity an angle.
            shrt_temp.qcontent = trig_conversion_factor * acos(1.0 / muni21);
            return shrt_temp;
        }


class munit_place
{
    friend class munit_quantity;
	friend class yrmo_date;
	private:
	munit_quantity mquan;
	int	  		   m_multiplicity;
	
	public:
    munit_place() { }								// Default constructor (never used)

    munit_place(munit_quantity ibunga, bool bbunga) // contructor
	{
		munit_quantity pshrt_temp_q = ibunga;

		if (bbunga) pshrt_temp_q.qcontent = 0.0; 	/* Set qcontent zero with a given unit, 
												  	 	 			e.g. 0°C  or 0°F					  */

        mquan = pshrt_temp_q; m_multiplicity = 1;
        return;
	}

	int get_multiplicity() { return m_multiplicity; }

	munit_place operator+(munit_place gbunga)
	{
		munit_place pshrt_temp;	
		pshrt_temp.mquan = this->mquan + gbunga.mquan;
		pshrt_temp.m_multiplicity = this->m_multiplicity + gbunga.m_multiplicity;
		return pshrt_temp;
	}
		
	munit_place operator-(munit_place gbunga)
	{
		munit_place pshrt_temp;	
		pshrt_temp.mquan = this->mquan - gbunga.mquan;
		pshrt_temp.m_multiplicity = this->m_multiplicity - gbunga.m_multiplicity;
		return pshrt_temp;
    }


    munit_place operator+(munit_quantity qbunga)
    {
        munit_place pshrt_temp;
        pshrt_temp.mquan = this->mquan + qbunga;
        pshrt_temp.m_multiplicity = this->m_multiplicity;
        return pshrt_temp;
    }
    
    munit_place operator-(munit_quantity qbunga)
    {
        munit_place pshrt_temp;
        pshrt_temp.mquan = this->mquan - qbunga;
        pshrt_temp.m_multiplicity = this->m_multiplicity;
        return pshrt_temp;
    }

    string munit_PL_readout(munit_quantity readout_unit, munit_place readout_base, int PL_significant = 6, string PL_addon = "PL")
    {
        munit_quantity mquan_out_base = readout_base.mquan;
        double PL_shift = mquan_out_base.qcontent;
        return munit_readout(mquan, readout_unit,  PL_significant, PL_addon, PL_shift);
    }

	munit_quantity quanget() { if (m_multiplicity != 0) errorqq("gotta have a multiplicity of zero"); return mquan; }
};
#endif
