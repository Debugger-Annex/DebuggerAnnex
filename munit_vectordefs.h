#ifndef MUNIT_VECTOR_KOLUTCH						//    just the usual stuff to make sure that the material in this file
#define MUNIT_VECTOR_KOLUTCH						/*    is included once and only once.

--- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - -
The four following macros are used below under munit_place																													  */

#define Centigrade(XDEGG) (centigrade_base + XDEGG * Kelvin_dg)
#define Fahrenheit(XDEGG) (fahrenheit_base + XDEGG * Rankine_dg)
#define Fahrenheit_readout(XTEMP, XTEMP_SIG) XTEMP.munit_PL_readout(Rankine_dg, fahrenheit_base, XTEMP_SIG)
#define Centigrade_readout(XTEMP, XTEMP_SIG) XTEMP.munit_PL_readout(Kelvin_dg,  centigrade_base, XTEMP_SIG)

																																											  /*
--- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - -

Start with the quovinks for the units mentioned in munit_preliminaries.h
																																											  */
    quovink(trig_second, 34215);
    quovink(trig_degree, degrees);
    quovink(gradient, grad);
    quovink(radians, radian);
    quovink(revolution, revolutions);

    quovink(time_second, 34216);
    quovink(time_minute, minute);
    quovink(hour, hour);
    quovink(day, day);
    quovink(week, week);
																																											  /*
--- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - -

                                First, let's define the fundamental unit types, using the constructor in the munit_trying.h file.


    munit_quantity angle(FUNDAMENTAL, 0);			//	  amgle  These units of angle and time are defined in the munit_preliminaries.h file.
    munit_quantity  time(FUNDAMENTAL, 1);			//    time	 Defining twice can cause problems. And hence the comment status of these two lines.
                                                                                                                                                                              */
    munit_quantity  gram(FUNDAMENTAL, 2);			//	  mass

    munit_quantity	  mm(FUNDAMENTAL, 3);			//	  length (or distance) mm = millimeter
    munit_quantity  mimm(FUNDAMENTAL, 3);			//	  The mimm unit is used just once in the definition of square mm (area).


    munit_quantity coulomb(FUNDAMENTAL, 4);			/*    electric charge
    													  		 An alternative would be to define current (ampere) as the fundamental unit;
    													  		 and then let electrical charge be current * time.
																																											  */
	munit_quantity  Kelvin_dg(FUNDAMENTAL, 5, 9);	//	  temperature difference
	munit_quantity Rankine_dg(FUNDAMENTAL, 5, 5);	/*			 This is an important quantity in thermodynamics.
														  		 Temperature (degrees Fahrenheit or Centrigrade is not quite the same thimg.
														  		 See below in the section on muniy_place for more abut Fahrenheit and Centigrade.

																																											  */
    quovink(gram, gram);				  // mass
    quovink(mm, mm);					  // length
    quovink(coulomb, coulomb);		  	  // electric charge
    quovink(Kelvin_dg,  K°);	  		  // temperature difference
    quovink(Rankine_dg, R°);			  																																	   /*
																		  
	
--- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - ----- -- - --- -- - -

    now, let's construct units using scalar multiplication and division.
                                                                                                                                                                               */
    munit_quantity meter = 1000.0 * mm;	  quovink(meter, m);
    munit_quantity cm   = 10.0 * mm;      quovink(cm, cm);
    munit_quantity km   = 1000000.0 * mm; quovink(km, km);
 
    munit_quantity inch = 25.4 * mm;      quovink(inch, 15257);
    munit_quantity foot = 12.0 * inch;	  quovink(foot, ft);
    munit_quantity yard = 36.00 * inch;	  quovink(yard, yards);
    munit_quantity mile = 63360.0 * inch; quovink(mile, miles);		   // Why not just 5280 * foot? Answer: to avoid some round-off error.
    munit_quantity furlong = 660.0 * foot; quovink(furlong, furlongs);   // an eighth of a mile

    munit_quantity kg   = 1000.0 * gram;  quovink(kg, kg);
    munit_quantity lb = 453.59237 * gram; quovink(lb, lb);
    munit_quantity oz = lb / 16;          quovink(oz, oz);
																																												/*
--- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - -

    now, the plural forms and synonyms of the above
																																												*/
#define meters meter
#define inches inch
#define feet foot
#define ft foot
#define	yards yard
#define miles mile
#define fulongs furlong

#define ounce oz
#define ounces oz
#define pound lb
#define pounds lb
#define lbs lb

#define time_seconds time_second
#define time_minutes time_minute
// #define hours hour
#define days day
#define weeks week
#define grams gram
                                                                                                                                                                                /*
 --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - --- -- - -

        now, the "composite" units -- the quantities that are multiplicative combinations of the fundamental units ...
                                                                                                                                                                                */
//  munit_quantity area(length * distance);								  // area
    munit_quantity sq_mm = mm * mm;				quovink(sq_mm, 	  mm²);
    munit_quantity sq_meter = meter * meter;	quovink(sq_meter, m²);
    munit_quantity sq_cm = cm * cm;				quovink(sq_cm,	  cm²);
    munit_quantity sq_km = km * km;				quovink(sq_km,	  km²);
    
    munit_quantity sq_inch = inch * inch;		quovink(sq_inch, inch²);
    munit_quantity sq_foot = foot * foot;		quovink(sq_foot, ft²);
    munit_quantity sq_yard = yard * yard;		quovink(sq_yard, yd²);
    munit_quantity sq_mile = mile * mile;		quovink(sq_mile, mile²);
    
    munit_quantity acre    = sq_mile / 640;		quovink(acre, acres);
    																																										    /*
	On some web sites in looking up "acre" I found figures of 43560
	square feet plus some fraction. In some it says  43560 exactly.
	What should one believe?
	    																																										*/
        
//  munit_quantity volume(length * area);								  // volume
    munit_quantity cu_mm = mm * sq_mm;				quovink(cu_mm, 	  mm³);
    munit_quantity cu_meter = meter * sq_meter;		quovink(cu_meter, m³);
    munit_quantity cu_cm = cm * sq_cm;				quovink(cu_cm,	  cm³);
    munit_quantity cu_km = km * sq_km;				quovink(cu_km,	  km³);
    munit_quantity cc(cu_cm);

    munit_quantity cu_inch = inch * sq_inch;		quovink(cu_inch, inch³);
    munit_quantity cu_foot = foot * sq_foot;		quovink(cu_foot, ft³);
    munit_quantity cu_yard = yard * sq_yard;		quovink(cu_yard, yd³);
    munit_quantity cu_mile = mile * sq_mile;		quovink(cu_mile, mile³);
    munit_quantity ac_feet = foot * acre;			quovink(ac_feet, acre-foot);

    munit_quantity USgallon  = cu_foot / 7.48051948; quovink(USgallon, gallon); 																								/*
	
	This number 7.48051948 I now find on the Internet. Many years ago
	I found 7.48051945 on a calculator. What should one believe?
																																												*/ 
	munit_quantity UKgallon = 1.2009499204287 * USgallon;
    munit_quantity Imperial_gallon(UKgallon);		quovink(UKgallon, Imp_gallons);
	munit_quantity litre = UKgallon / 4.54609;
    munit_quantity ml	 = UKgallon * 0.00454609;	quovink(ml, ml);

    munit_quantity fl_oz = USgallon / 128.0;		quovink(fl_oz, fl_oz);// volume: kitchen measure
    munit_quantity cup   = USgallon / 16.0;			quovink(cup, cup);
    munit_quantity tbsp  = USgallon / 256.0;		quovink(tbsp, tbsp);
    munit_quantity tsp   = USgallon / 768.0;		quovink(tsp, tsp);


    munit_quantity mph   = miles / hour;			quovink(mph, mph);	  // velocity
    munit_quantity kph	 = km / hour;

    munit_quantity mach = 761 * mph;				quovink(mach, 42217);
																																												/* 
    mach = the speed of sound; Actually, the speed of sound is different
    	   depending on altitude.
																																												*/
    munit_quantity ft_per_sec = ft / time_second;	quovink(ft_per_sec, ft_per_sec);
	munit_quantity cm_per_sec = cm / time_second;
	munit_quantity  m_per_sec = meter / time_second;


    const munit_quantity G_Acc = 980.665 * cm/(time_second * time_second);// acceleration

	munit_quantity ft_per_sec_sec = ft_per_sec / time_second;
	munit_quantity cm_per_sec_sec = cm_per_sec / time_second;
	munit_quantity m_per_sec_sec  =  m_per_sec / time_second;
	munit_quantity mph_per_sec = mph / time_second;																																/*												
	// Can your car go from zero to sixty in 2.9 seconds, like a Ferrari?																												*/

    munit_quantity newton = kg * m_per_sec_sec;		quovink(newton, nt);  // force
    munit_quantity dyne	  = gram * cm_per_sec_sec;	quovink(dyne, dyne);
																																												/*
	Amy unit of mass corresponds to a unit of force.
	Just multiply the mass unit by G_Acc.

	For example, one pound of force = 1 * lb * G_Acc.

	in readong out a force quantity, one might want to use the
	construct munit_readout(force quantity / G_Acc, mass unit);
																																												*/
	munit_quantity foot_pound = ft * lb * G_Acc;						  // energy
	munit_quantity joule	  = newton * meter;
	munit_quantity erg		  = dyne   * cm;

	munit_quantity calorie	  = joule  * 4.18399999983771;																														/*
    raises one gram of water one degree Kelvin	*/	quovink(calorie, calorie);

    munit_quantity BtU		  = 1055.06 * joule;	quovink(BtU, BtU);
	munit_quantity kcal		  = 4186.8  * joule;


	
    munit_quantity ampere = coulomb / time_second;	quovink(ampere, amp); // electricity
    munit_quantity volt   = joule / coulomb;
    

    

    munit_place centigrade_base(Kelvin_dg, true); // munit_place contructor
    munit_place fahrenheit_base = centigrade_base - 32.0 * Rankine_dg;    // temperature
    quovinkPL(Rankine_dg, deg_F, PUTIN_PL);
    quovinkPL(Kelvin_dg,  deg_C, PUTIN_PL);

#endif


