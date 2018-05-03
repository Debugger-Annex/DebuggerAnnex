#define false0 0 // These two statements are used, because my C++ compiler
#define true1 1  // seems to have a hangup about passing 'bool' parameters.

#define YRMO_CONSTRUCTOR_DEFAULT -32746
#define make_yrmo_date_from_short_triple(XRAQ88IBO) yrmo_date(XRAQ88IBO.memb1, XRAQ88IBO.memb2, XRAQ88IBO.memb3)
// You need a short_triple declared fkr XRAQ88IBO.


#define t400_yDAYS 146097
#define t100_yDAYS 36524
#define t4_yDAYS 1461
#define t1_yDAYS 365

#define nt400_yDAYS -146097
#define nt100_yDAYS -36524
#define nt4_yDAYS -1461
#define nt1_yDAYS -365

#define t400_yDAYS_M1 146096
#define t100_yDAYS_M1 36523
#define t4_yDAYS_M1 1460
#define t1_yDAYS_M1 364

#define END_2C_PERIOD_FROM_1900 73049

/*
#include <iostream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <QCoreApplication>
using namespace std;

									0			1			2			3			4			5			6		   7		   8		   9		  10		  11		 12		   13	   14		15		 16			17		 18		 19		 20		 21		 22		23
                                                                                                                                                                                                                                                                                             */
string FADJ_Month_Names[] = {	"March"	,	"April"	,	"May"	,	"June"	,	"July"	,	"August",	"Sept"	,	"Oct"	,	"Nov"	,	"Dec"	,	"Jan"	,	"Feb"	,"March" , "April" , "May" , "June" , "July" , "August" , "Sept" , "Oct" , "Nov" , "Dec" , "Jan", "Feb" };
short FADJ_Month_limits[] = {	  31	,	  30	,	  31	,	  30	,	  31	,	  31	,	  30	,	 31		,	 30		,	  31	,	  31	,	  28	,	31	 ,	  30   ,   31  ,   30	,	31	 ,	  31	,	30	 ,	 31	 ,	 30  ,	 31	 ,	 31	,	28	};
short FADJ_Month_accum[] =  {	   0	,	  31	,	  61	,	  92	,	 122	,	 153	,	 184	,	214		,	245		,	 275	,	 306	,	 337	,  365	 ,	 396   ,  426  ,  457	,  487	 ,	 518	,  549	 ,	579	 ,	610	 ,	640	 ,	671	,  702	};


string RAW_Month_Names[] =  {	"Jan"	,	"Feb"	,	"March"	,	"April"	,	"May"	,	"June"	,	"July"	, "August"	,  "Sept"	,	"Oct"	,	"Nov"	,	"Dec"	, "Jan"	 ,	"Feb"  ,"March", "April",  "May" ,	"June"	, "July" ,"August",	"Sept",	"Oct", "Nov", "Dec" };
short  RAW_Month_limits[] = {	  31	,	  28	,	  31	,	  30	,	  31	,	  30	,	  31	,	 31		,	 30		,	  31	,	 30		,	  31	,	31	 ,	  28   ,   31  ,   30	,	31	 ,	  30	,	31	 ,	 31	  ,	 30	 ,	 31	 ,	 30 ,	31	};
short  RAW_Month_accum[]  = {	   0	,	  31	,	  59	,	  90	,	 120	,	 151	,	 181	,	212		,	243		,	 273	,	304		,	 334	,  365	 ,	 396   ,  424  ,  455	,  485	 ,	 516	,  546	 ,	577	  ,	608	 ,	638	 ,  669	,  699	};



typedef struct
{
	int quot;
	int rem;
} divv_t;

typedef struct
{
	short memb1;
	short memb2;
	short memb3;
} short_triple;

divv_t searchFADJ(int searchargFADJ)									// This is a bastardized binary search.
{
	int xi, xii;

	if (searchargFADJ >= 184) // 6
	{	if (searchargFADJ >= 275) { xi = 12 ;}		// 9
		else					  { xi = 9;  } }

	else
	{
		if (searchargFADJ >= 92 ) { xi = 6;  }		// 3
		else					  { xi = 3;  } }

	do { xii = FADJ_Month_accum[--xi]; } while (xii >  searchargFADJ);
	divv_t divret; divret.quot = xi; divret.rem = xii;
	return divret;
}


short_triple striple(string stringin)
{
	long xlm, xld, xly;
    char *moving_ptr; char delimiters_of_tokens[] = " /";

	int ix = stringin.length() + 1;
	char *date_to_strtok = new char[ix];
	strcpy(date_to_strtok, stringin.c_str());
	string Error_msg = stringin + string(" is not a valid date");

	moving_ptr = strtok(date_to_strtok, delimiters_of_tokens); if(moving_ptr == NULL) errorqq (Error_msg); xlm = strtol(moving_ptr, NULL, 10); if (xlm == 0) errorqq(Error_msg);
	moving_ptr = strtok(NULL,			delimiters_of_tokens); if(moving_ptr == NULL) errorqq (Error_msg); xld = strtol(moving_ptr, NULL, 10); if (xld == 0) errorqq(Error_msg);
	moving_ptr = strtok(NULL,			delimiters_of_tokens); if(moving_ptr == NULL) errorqq (Error_msg); xly = strtol(moving_ptr, NULL, 10); if (xly == 0) errorqq(Error_msg);

	short_triple striple_ret; striple_ret.memb2 = (short) xlm; striple_ret.memb3 = (short) xld; striple_ret.memb1 = (short) xly;
	delete [] date_to_strtok;
	return striple_ret;
}

divv_t divv(int ddend, int ddivisor)									// assuming a non-negative divisor
{
	divv_t vlvv;
	if (ddivisor == 0)													// Zero divisor is considered an error.
	{
		schTream.str(""); schTream << "zero divisor in divv " << ddend;
		errorqq(schTream.str());
	}
	int qx = ddend / ddivisor; int rx = ddend - qx * ddivisor;
	if ((ddend < 0) && (rx != 0)) { --qx; rx += ddivisor; }
	vlvv.quot = qx; vlvv.rem = rx; return vlvv;
}

divv_t floor_divv(int ddend_z, int ddivisor_z) { divv_t szbcfxjththzsrmoj = divv(ddend_z, ddivisor_z); szbcfxjththzsrmoj.quot *= ddivisor_z; return szbcfxjththzsrmoj; }


bool is_leapyr_N(int yrtest)										// Is the unadjusted year yrtest    a leap year?
{																// An		adjusted year yrtest is a leap yeat  if and if yrtest - 1 is.
	int yt = yrtest;
	if ((yt % 4)	!= 0) return false;
	if ((yt % 400)  == 0) return true;
	if ((yt % 100)  == 0) return false;
	return true;
}


class yrmo_qty
{

  friend class yrmo_date;

  private:
	short yrq; // might be zero
	short moq; // might be zero

  public:
	yrmo_qty(short yrxx = 0, short moxx = 0) {yrq = yrxx; moq = moxx;}

	int	  yrmo_dragout() { return 12 * yrq + moq; }
	double dyrmo_dragout() { return (double) yrmo_dragout(); }

	void adjust12() { divv_t zzvross = divv(yrmo_dragout(), 12); yrq = zzvross.quot; moq = zzvross.rem; }

	yrmo_qty operator+(yrmo_qty quinn) { yrmo_qty yrmo_ret; yrmo_ret.yrq = yrq + quinn.yrq;  yrmo_ret.moq = moq + quinn.moq; return yrmo_ret; }
	yrmo_qty operator-(yrmo_qty quinn) { yrmo_qty yrmo_ret; yrmo_ret.yrq = yrq - quinn.yrq;  yrmo_ret.moq = moq - quinn.moq; return yrmo_ret; }
	yrmo_qty operator*(int	 iquinn)   { yrmo_qty yrmo_ret; yrmo_ret.yrq = yrq * iquinn;	 yrmo_ret.moq = moq * iquinn;	 return yrmo_ret; }
	double operator/(yrmo_qty quinn) { return dyrmo_dragout() / quinn.dyrmo_dragout(); }
};
	yrmo_qty operator*(int nbo, yrmo_qty ygar) { return ygar * nbo; }

class yrmo_date		/* date in yrmo form, e.g. (year = 2001, month = 5, day of month = 2) ... The string form 5/2/2001 is an "abbreviated" form.
					   The Julian form is the number of days before or after a "base" date -- somewhat analobous to based pointers in C/C++.
																																		   */
{
  private:
	bool  yrmo_adjusted;
					// false = raw		form, meaning that  (yrq = 2000, moq = 3,  daymo = 1)  represents 3/1/2000.
					/* true  = adjusted form, meaning that  (yrq = 2000, moq = 0,  daymo = 0)  represents 3/1/2000.
													   and  (yrq = 1999, moq = 11, daymo = 28) represents 2/28/2000.

							   This date  in admusted form (yrmo_adjusted = true) is analogous to a fiscal year from
							   March 1 to end of February. (28th or 29th). It is used internally for converting from
							   from yrmo form to Julian and vice versa.

							   As you might know, some governments and businesses use fiscal years.

																																		   */
	short yrq;		// year	   See below the yrmo_adjust function.and yrmo_unadjust function
	short moq;		// month of the year -- begins with 1 if yrmo_adjusted is false, and 0 otherwise.
	short daymo;	// day of the month  -- begins with 0, "   "	"	    "   "	  "      "

  public:

	bool is_leapyr()												// Is the year yrtest a leap year?
	{
		int yt = yrq + (yrmo_adjusted ? 1 : 0);						// The adjusted year y is a leap year if and only if y + 1 is.
		if ((yt % 4)	!= 0) return false;
		if ((yt % 400)  == 0) return true;
		if ((yt % 100)  == 0) return false;
		return true;
	}


	yrmo_date(short yx = YRMO_CONSTRUCTOR_DEFAULT, short mx = YRMO_CONSTRUCTOR_DEFAULT, short dx = YRMO_CONSTRUCTOR_DEFAULT, int bbxI = 0)	   // constructor -- private members one by one
	{
	  if (yx == YRMO_CONSTRUCTOR_DEFAULT) {  }
	  else
	  {
		int limx;
		yrq = yx; moq = mx; daymo = dx; yrmo_adjusted = ((bbxI != 0) ? 1 : 0);
																																		   /*
		This seems trivial, of course. Now let's check for validity.
																																		   */
		if ((mx < (yrmo_adjusted ? 0 : 1)) || (mx > (yrmo_adjusted ? 11 : 12)) || (daymo < 1)) errorqq(yrmo_stringup() + string(" is not a valid date")); /*
		no negative month of the year; zero allowed for adjusted form -- no aero or negative day of the month							   */

		string favongq = (yrmo_adjusted ? FADJ_Month_Names[mx] : RAW_Month_Names[mx - 1]); // month name, for debugging only

		if (mx == (yrmo_adjusted ? 11: 2))	// limx = the number of days in Febtuary of the year yrq:
			limx = (is_leapyr() ? 29 : 28);	//		  29 for a leap year and 28 otherwise

		else limx = (yrmo_adjusted ? FADJ_Month_limits[mx] : RAW_Month_limits[mx - 1]);
											// limx = the number of days in month #mx of the year, if it isn't February

		if (dx > limx)  errorqq(yrmo_stringup() + string(" is not a valid date"));
	  }										// if the day of the month > limx, it's an error.
	}

	int	    yrmo_dragout() { return 12 * yrq + moq - (yrmo_adjusted ? 0 : 1); }															   /*

			This produces a "large month number", i.e. for a date like 5/2/2001, the large month number is 24016: 12 * 2001 + 5 - 1.

			The reverse function would be

			There  could  be  a class lmn_date, and  5/2/2001 would be	 lmn_date{ moq = 24016, daymo = 2 }. But there doesn't seem to
			be any need for any class lmn_date.

																																		   */
	void yrmo_adjust()					   /* Toggle adjusted and unadjusted form or this date { yrq, moq, daymo }.
											  Notice how the year and month numbers get adjusted in the process.
																																		   */
	{
		if (yrmo_adjusted)				   // if this date { yrq, moq, daymo } is in adjusted form,   make it unadjusted.
		{
			if (moq > 9)  { ++yrq; moq -= 9; }
			else		   moq += 3;
			yrmo_adjusted = false;
		}

		else							   // if this date { yrq, moq, daymo } is in unadjusted form, adjust it.
		{
			if (moq < 3)  { --yrq; moq += 9; }
			else		   moq -= 3;
			yrmo_adjusted = true;
		}
	}

	string yrmo_stringup()				  // Convert this date like { yrq = 2004, moq = 11, daymo 13 } to the string form   11/13/2004.
	{
		schTream.str("");				  // Clear out the string stream.
		schTream << moq << "/" << daymo<< "/" << yrq;
		if (yrmo_adjusted) schTream << " adjusted";
		return schTream.str();
	}

	yrmo_date yrmo_cannonical // This function is like the reverse of yrmo_dragout
	(		int dragged_out,  // dragout number produced by yrmo_dragout
			short dayover,	  // number of days in the month
			int y_adjustedI   // adjusted, like yrmo_adjusted described above in private members
			)
	{
		yrmo_date yrmo_ret;
		bool y_adjusted = ((y_adjustedI != 0 ) ? 1 : 0);
		divv_t zzvross = divv(dragged_out, 12);
		int yx = zzvross.quot; int mx = zzvross.rem;				// yx = the year number and mx = the month number.
		short dayovx = dayover;
//		int Feb_number = (y_adjusted ? 11 : 2);						// month number for February

		int limx = (y_adjusted ? FADJ_Month_limits[mx] : RAW_Month_limits[mx]);
		if (dayovx > 28 && mx == (y_adjusted ? 11 : 1) &&			// Make limx = the number of days in month #mx if #mx is not February
				is_leapyr_N(yx + y_adjustedI))  { limx = 29; }		// Adjust limx for February.

		if (dayovx > limx){											// If the number of days in the month is invalid, e.g. April 31, then make an adjustment.
			++mx;  dayovx -= limx; if (mx >= 12) {++yx; mx -= 12;}
		}
		yrmo_ret.daymo = dayovx; yrmo_ret.yrq = yx; yrmo_ret.moq = mx + (y_adjusted ? 0 : 1); yrmo_ret.yrmo_adjusted = y_adjusted;
		return yrmo_ret;
	}

	yrmo_date operator+(yrmo_qty addinx)
	{
		int drag1 = yrmo_dragout() + addinx.yrmo_dragout();
		int yrmo_adjustedI = (yrmo_adjusted ? true1: false0);
		return yrmo_cannonical(drag1, daymo, yrmo_adjustedI);
	}

	yrmo_date operator-(yrmo_qty addinx)
	{
		int drag1 = yrmo_dragout() - addinx.yrmo_dragout();
		int yrmo_adjustedI = (yrmo_adjusted ? true1: false0);
		return yrmo_cannonical(drag1, daymo, yrmo_adjustedI);
	}

	friend yrmo_date make_yrmo_from_string(string);

  private:
	friend yrmo_date make_yrmo_from_IJulian(int);
	friend int make_IJulian_from_yrmo(yrmo_date);

  public:
	friend yrmo_date make_yrmo_from__mPL_Julian(munit_quantity);
//	friend munit_quantity make_mPL_Julian_from_yrmo(yrmo_date);
};

	yrmo_date make_yrmo_from_IJulian(int JDate)
	{
		divv_t zcross;
		int accum_years, JM_Date;
		yrmo_date yrmo_make;

		if ((JDate >= -36525) && (JDate <= 36524))
		{																																    /*
			Over 99.9% of the dates we deal with will be between  February 29, 1900 and March 1, 2100, because that includes  the
			lifetimes of everyone alive today and most of their great grandcildren and most of their their grandparents. And that
			that justifies a simpler routine for this lion's share of the dates.
																																			*/
			accum_years = 1900;
			JM_Date = JDate + 36525;
																																			/*
			The reason why the routine for this two-century period is simple is that there is a leap year every four years,  with
			no exceptions.																											*/
		}

		else
		{
			accum_years = 2000; JM_Date = JDate;
			zcross = divv(JM_Date, t400_yDAYS); accum_years	+= zcross.quot * 400; JM_Date = zcross.rem;
			zcross = divv(JM_Date, t100_yDAYS);	accum_years += zcross.quot * 100; JM_Date = zcross.rem;
		}
		zcross = divv(JM_Date, t4_yDAYS); accum_years += zcross.quot * 4; JM_Date = zcross.rem;
		zcross = divv(JM_Date, t1_yDAYS); accum_years += zcross.quot	; JM_Date = zcross.rem;

		zcross = searchFADJ(JM_Date);
		int	rx = zcross.quot;

		yrmo_make.yrq = accum_years; yrmo_make.moq = rx; yrmo_make.daymo = JM_Date - FADJ_Month_accum[rx] + 1; yrmo_make.yrmo_adjusted = true;
		return yrmo_make;
	}

	int make_IJulian_from_yrmo(yrmo_date YDate)
	{
		divv_t zcross;
		int accum_days, JMY_Date, JMYE_Date = YDate.yrq;

		accum_days = 0; JMY_Date = JMYE_Date - 2000;
        zcross = divv(JMY_Date, 400); accum_days += zcross.quot * t400_yDAYS; JMY_Date = zcross.rem;
		zcross = divv(JMY_Date, 100); accum_days += zcross.quot * t100_yDAYS; JMY_Date = zcross.rem;
		zcross = divv(JMY_Date, 4);	  accum_days += zcross.quot * t4_yDAYS;

		accum_days += 365 * zcross.rem + FADJ_Month_accum[YDate.moq] + YDate.daymo - 1;

		return accum_days;
	}

	yrmo_date make_yrmo_from_string(string in_ko_str) { short_triple stpXX = striple(in_ko_str); yrmo_date yrmo_ret(stpXX.memb1, stpXX.memb2, stpXX.memb3); return yrmo_ret; }


