                                                                                                                                                                                /*
---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -

The following two statements should be st the top of every #included file, the very first two lines, in order to make sure that the file is #included once and only once.
																																													*/ 
#ifndef HGQMKIERTZSE__FUYKEP// The name in these two lines is just random letters -- not repeated ever again. Just make sure it's the same in both lines.
#define HGQMKIERTZSE__FUYKEP
																																													/*
---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -

THE USER MUST NEVER make any changes to this file. The trigonometric functions in the munit_quantities.h  file depend on what's in here.

																																													*/ 
    munit_quantity trig_second(FUNDAMENTAL,   0, 1);           // As is said in other places in this package,
    munit_quantity trig_minute(FUNDAMENTAL,   0, 60);          // distinctive names are needed, to distinguish trigonometric minutes and seconds from time minutes and seconds.

    munit_quantity trig_degree(FUNDAMENTAL,   0, 3600);        // As you know, nine degrees = ten gradients.
    munit_quantity    gradient(FUNDAMENTAL,   0, 3240);        // And 9 * 3600 = 10 * 3240

    munit_quantity  pi_radians(FUNDAMENTAL,   0, 648000);      // And pi radians = 180 * trig_degrees. (180 * 3600)


    munit_quantity      radian(FUNDAMENTAL,   0, 648000 / pi); // And 180 degrees   (180 * trig_degree) = pi radians
                                                               // And 200 gradients (200 *  gradient)   = pi radians (pi * radian)


    munit_quantity   revolution(FUNDAMENTAL,  0, 1296000);     /* One revolution is 2 * pi readians, of course. We all have seen "rpm" or "revolutions per second".


---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -

Now things related to time
																																													*/
    munit_quantity  time_second(FUNDAMENTAL, 1);				// As is said in other places in this package,
	munit_quantity  time_minute(FUNDAMENTAL, 1, 60);			// distinctive names are needed, to distinguish trigonometric minutes and seconds from time minutes and seconds. 
	munit_quantity		   hour(FUNDAMENTAL, 1, 3600);
	munit_quantity			day(FUNDAMENTAL, 1, 86400);
	munit_quantity		   week(FUNDAMENTAL, 1, 604800);

	yrmo_qty  year(1, 0);
	yrmo_qty month(0, 1);
																																													/*
---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -

Now for the quovink statements needed for the above-defined units:
																																													*/
	string xstringup_carrier; char *xstringup_fetched;			/* needed for the quovink and quovini macros
																   which are needed for the munit_readout function.
                                                                                                                                                                               		*/

																																													/*
---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -  ---  --   ---  -
    //    now the plural forms
                                                                                                                                                                                    */
#define trig_degrees trig_degree
#define trig_minutes trig_minute
#define trig_seconds trig_second
#define gradients	 gradient
#define radians		 radian

#define years year
#define months month

#define time_seconds time_second
#define time_minutes time_minute
#define hours your
#define days day
#define weeks week

                                                                                                                                                                                    /*
THE USER MUST NEVER make any changes to the above statements. The date/time routines in Date_arithmetic.h and Debugger_Annex_Functions.h depend on them.
                                                                                                                                                                                    */ 
#endif

