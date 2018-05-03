#define make_MU_from_string

 yrmo_date make_yrmo_from_MUdate(munit_place MUdate) // make a yrmo date from a munit_place.
 {


     // #1. check to make sure that MUdate is a valid munit_place. (Multiplicity = 1).
            if (MUdate.get_multiplicity() != 1)
            {
                errorqq("multiplicity of a munit place is wrong");
            }

     // #2. check to make sure thst MUdate is a valid date.        (time units)
            munit_quantity mquan_MUdate = (MUdate - munit_date_base).quanget();
            if (munit_compare(mquan_MUdate, jqday) == 3) errorqq("invalid place in time");

     // #3. Get the integer number of days and, from that, get the yrno date structure.
            int IJ_MUdate = (mquan_MUdate / jqday).scalar_get();
     return make_yrmo_from_IJulian(IJ_MUdate);
 }

 munit_place make_MU_from_yrmo(yrmo_date YRM_date)
 {
     double IJ_Day = 86400;
     double IJ_MUdate = make_IJulian_from_yrmo(YRM_date);
     munit_quantity MUtime(FUNDAMENTAL, 1, IJ_Day * IJ_MUdate);
	 return munit_place(MUtime, false);
 }

#define make_MU_from_string(xst)  make_MU_from_yrmo(make_yrmo_from_string(xst))
