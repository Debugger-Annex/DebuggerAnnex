// Put any required #include statements here.
// Don't put in any main(int argc, char *argv[]);. That is included in munit_QP_standard.h.

#include "munit_QP_standard.h"
 
munit_quantity  my_weight = 197.3 * lbs;
munit_quantity  airplane_speed = 675.0 * mph;
munit_quantity  Concorde_speed = mach * 2.04;
munit_quantity  package_net_weight = lb / 4.0;		// i.e. a quarter of a pound
munit_quantity  package_nt_weight  = lb * 0.25;		// i.e. a quarter of a pound – same thing
munit_quantity  vanilla_1_amount = 5.2  * grams;	// weight measure
munit_quantity  vanilla_2_amount = 1.5  * tsp;		// volume measure
munit_quantity  waiting_time =  20 * time_minutes;

//munit_quantity  Xu =  vanilla_1_amount + vanilla_2_amount; //	This is an error -- unlike quantities.
//																Should this package have a table of volume/weight densities of every known powder and liquid?
//																That is a rhetorical question, of course.

munit_quantity  distance_driven = 50.47 * miles + 40.52 * km;// not an error -- conversion factor put in


// This package makes a special provision for trigonometric and inverse trigonometric functions.

munit_quantity angle_45 = 45 * trig_degrees; munit_quantity angle_33g = (100.0 / 3.0) * gradients;

double aorth_45_d_sin = sin(angle_45);  // value: 0.5 * sqrt(2)
double aorth_45_d_tan = tan(angle_45);  // value: 1
double aorth_33_g_sin = sin(angle_33g); // value: 0.5
double aorth_33_g_cos = cos(angle_33g); // value: sqrt(3) / 2
double aorth_33_g_tan = tan(angle_33g); // value: sqrt(3) / 3

munit_quantity xxiz = Atan(sqrt(3.0) / 3.0); // value: 60 degrees
munit_quantity xxia = Asin(sqrt(2.0) / 2.0); // value: 45 degrees

// Notice the capital “A” in the names of the inverse trigonometric functions.


// Now let's try some places.

munit_place comfortable_room_temperature  = Fahrenheit(72); munit_place uncomfortable_outdoor_temperature = Centigrade(35);
munit_place healthy_body_temperature      = Centigrade(37);
munit_place dangerous_body_temperature = healthy_body_temperature +  6.4 * Rankine_dg;                      /*
This would be 105°F – the kind of fever that can result in serious brain damage.
Whatever the cause, the patient must be packed in ice to bring the fever down.
                                                                                                            */
yrmo_date   D_Day	= make_yrmo_from_string("6/6/1944"); // string to date
munit_place _D_Day_m  = make_MU_from_string("6/6/1944");
yrmo_date	important_anniversary    =  D_Day + 50 * years;
/* around this 50th anniversary of D Day, several TV channels were continuously
on about memories of World War II.  I kind of enjoyed  the interviews with people like the Andrews Sisters and Vera Lynn.	*/
munit_place _D_Day  = make_MU_from_yrmo(D_Day);
munit_place an_important_anniversary = make_MU_from_yrmo(important_anniversary);

// To read out a munit_quantity, (i.e. convert it to a displayable string) use the munit_readout function, like this:

string reading_out_m = munit_readout(distance_driven, mile, 9);
// string value is "75.6479607 miles"

string reading_out_k = munit_readout(distance_driven, km, 9);                                          
// string value is "121.743592 km" without the quotes.

// The third parameter, which was nine in the above two examples, defaults to six.

munit_quantity Sunday_distance_driven = 50.0 * miles + 40.0 * km;
string Sunday_reading_out_k = munit_readout(Sunday_distance_driven, km);                                                  
// string value is "120.467 km"

// If fewer than the designated number of significant figures is sufficient for the exact value,
// the trailing zeroes are eliminated.

string Sunday_reading_out_k9 = munit_readout(Sunday_distance_driven, km, 9);                                      
// string value is "120.4672 km" –  not “120.467200 km”

// Sometimes one might want the unit to be first instead of last.
munit_quantity  Fast_Concorde = 1825.3 * mph;
string PHigh_Concorde = munit_readout(Fast_Concorde, mach);


//Places can be read out in the same way.

string temp_hly = Fahrenheit_readout(healthy_body_temperature, 6);
// string value: “98.6 deg_F”

string temp_dng = Fahrenheit_readout(dangerous_body_temperature, 6);
/* This would be 105°F – the kind of fever that can result in serious brain damage. Whatever the cause, the patient must be packed in ice to bring the fever down.	*/

string temp_rcm = Centigrade_readout(comfortable_room_temperature, 9);
// string value: “22.2222222 deg_C”  Nine significant figures were called for.

string temp_out = Fahrenheit_readout(uncomfortable_outdoor_temperature, 6);
// string value: “95 deg_C”  uncomfortable outdoor temperature

// Some of the unit names in the second parameter of munit_readout generate “split string”  results. Examples:

munit_quantity xxiat  = 52.0 * trig_degrees + 5.0 * trig_seconds + 78.0 * trig_minutes;
string aoXXSt = munit_readout(xxiat, trig_seconds);
// string value: "53 degrees 18 minutes 5 seconds”

munit_quantity xxiatu  = 1410.0 * ft;
string aoXXSu = munit_readout(xxiatu, inches);
// string value: "117 ft 6 inches"

munit_quantity xxiatuv = 10677.5 * ft;
string aoXXSm = munit_readout(xxiatuv, inches);                                                                                                                     /*
   string value: "2 miles 117 ft 6 inches"

-- -- -  -- -- -  -- -- -  -- -- -  -- -- -  -- -- -  -- -- -  -- -- -  -- -- -  -- -- -  -- -- -  -- -- -  -- -- -  -- -- -  -- -- -  -- -- -  -- -- -  -- -- -  -- -- -

            Date Aritnmetic examples
                                                                                                                                                                    */
int myo = 4 * t4_yDAYS + t1_yDAYS + 245 + 20;			// Julian date for 11/21/2017

munit_quantity rrso = day * (myo);				   munit_place	rsorta_00(rrso, false); // 11/21/2017

               rrso = day * (myo -      t4_yDAYS); munit_place	rsorta_04(rrso, false); // 11/21/2013
               rrso = day * (myo -  4 * t4_yDAYS); munit_place	rsorta_16(rrso, false); // 11/21/2001
               rrso = day * (myo -  5 * t4_yDAYS); munit_place	rsorta_20(rrso, false); // 11/21/1997
               rrso = day * (myo - 10 * t4_yDAYS); munit_place	rsorta_40(rrso, false); // 11/21/1977
               rrso = day * (myo - 20 * t4_yDAYS); munit_place	rsorta_80(rrso, false); // 11/21/1917
               rrso = day * (myo - t400_yDAYS);	   munit_place	rsorta_9a(rrso, false); // 11/21/1617
               rrso = day * (-367);				   munit_place	rsorta_9b(rrso, false); //  2/28/1999
               rrso = day * (-146096);			   munit_place	rsorta_9c(rrso, false); //  3/ 2/1600

yrmo_date sorta_00 = make_yrmo_from_MUdate(rsorta_00); // 11/21/2017
yrmo_date sorta_04 = make_yrmo_from_MUdate(rsorta_04); // 11/21/2013
yrmo_date sorta_16 = make_yrmo_from_MUdate(rsorta_16); // 11/21/2001
yrmo_date sorta_20 = make_yrmo_from_MUdate(rsorta_20); // 11/21/1997
yrmo_date sorta_40 = make_yrmo_from_MUdate(rsorta_40); // 11/21/1977
yrmo_date sorta_9a = make_yrmo_from_MUdate(rsorta_9a); // 11/21/1617
yrmo_date sorta_9b = make_yrmo_from_MUdate(rsorta_9b); //  2/28/1999
yrmo_date sorta_9c = make_yrmo_from_MUdate(rsorta_9c); //  3/ 2/1600

munit_place usorta_00 = make_MU_from_yrmo(sorta_00); // 11/21/2017 -- 6474
munit_place usorta_04 = make_MU_from_yrmo(sorta_04); // 11/21/2013 -- 5013
munit_place usorta_16 = make_MU_from_yrmo(sorta_16); // 11/21/2001 --  630
munit_place usorta_20 = make_MU_from_yrmo(sorta_20); // 11/21/1997 -- -831
munit_place usorta_40 = make_MU_from_yrmo(sorta_40); // 11/21/1977 -- -8136
munit_place usorta_9a = make_MU_from_yrmo(sorta_9a); // 11/21/1617 -- -139623
munit_place usorta_9b = make_MU_from_yrmo(sorta_9b); //  2/28/1999 -- -367
munit_place usorta_9c = make_MU_from_yrmo(sorta_9c); //  3/ 2/1600 -- -146096

yrmo_date xsorta_00 = sorta_00; xsorta_00.yrmo_adjust();  // 11/21/2017
yrmo_date xsorta_04 = sorta_04; xsorta_04.yrmo_adjust();  // 11/21/2013
yrmo_date xsorta_16 = sorta_16; xsorta_16.yrmo_adjust();  // 11/21/2001
yrmo_date xsorta_20 = sorta_20; xsorta_20.yrmo_adjust();  // 11/21/1997
yrmo_date xsorta_40 = sorta_40; xsorta_40.yrmo_adjust();  // 11/21/1977
yrmo_date xsorta_9a = sorta_9a; xsorta_9a.yrmo_adjust();  // 11/21/1617
yrmo_date xsorta_9b = sorta_9b; xsorta_9b.yrmo_adjust();  //  2/28/1999
yrmo_date xsorta_9c = sorta_9c; xsorta_9c.yrmo_adjust();  //  3/ 2/1600

yrmo_date zsorta_00 = xsorta_00; zsorta_00.yrmo_adjust();  // 11/21/2017
yrmo_date zsorta_04 = xsorta_04; zsorta_04.yrmo_adjust();  // 11/21/2013
yrmo_date zsorta_16 = xsorta_16; zsorta_16.yrmo_adjust();  // 11/21/2001
yrmo_date zsorta_20 = xsorta_20; zsorta_20.yrmo_adjust();  // 11/21/1997
yrmo_date zsorta_40 = xsorta_40; zsorta_40.yrmo_adjust();  // 11/21/1977
yrmo_date zsorta_9a = xsorta_9a; zsorta_9a.yrmo_adjust();  // 11/21/d1617
yrmo_date zsorta_9b = xsorta_9b; zsorta_9b.yrmo_adjust();  //  2/28/1999
yrmo_date zsorta_9c = xsorta_9c; zsorta_9c.yrmo_adjust();  //  3/ 2/1600

return aothello.exec();
}
