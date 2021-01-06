///////////////////////////////////////////////////////////////////////////////
// initialize MC datasets and corresponding histogram files
// for a given dataset tehre could be several histograms files corresponding to different
// histogramming jobs
///////////////////////////////////////////////////////////////////////////////
#ifndef __init_local_datasets__
#define __init_local_datasets__

#include "Stntuple/scripts/stn_dataset.hh"
#include "Stntuple/scripts/stn_book.hh"

//-----------------------------------------------------------------------------
// init datasets associated with the given book
//-----------------------------------------------------------------------------
void init_local_datasets(stn_book* Book) {
  stn_dataset_t* d;
  hist_file_t*   hf;
//-----------------------------------------------------------------------------
// the best way to manage multiple datasets is to arrange them alphabetically
//-----------------------------------------------------------------------------
  if (strcmp(Book->Name(),"mdc2020") == 0) {
    d  = Book->NewDataset ("mdc2020.no-primary-mix-d"  ,"",-1,1000);
    hf = Book->NewHistFile("mdc2020.no-primary-mix-d" ,"","straw_hit_ana");
  }
  else if (strcmp(Book->Name(),"su2020") == 0) {
    d  = Book->NewDataset ("su2020.cele0s51b0" ,"",-1,   1000000); 
    hf = Book->NewHistFile("su2020.cele0s51b0" ,"","su2020_track_ana_dar_11_1070"  );

    d  = Book->NewDataset ("su2020.cele0s51b1" ,"",-1,   1000000); 
    hf = Book->NewHistFile("su2020.cele0s51b1" ,"","su2020_track_ana_dar_11_1070");
    hf = Book->NewHistFile("su2020.cele0s51b1" ,"","pid_emuana");

    d  = Book->NewDataset ("su2020.cele0s51b2" ,"",-1,   1000000); 
    hf = Book->NewHistFile("su2020.cele0s51b2" ,"","track_comp_use_mva_ffff_1070");
    hf = Book->NewHistFile("su2020.cele0s51b2" ,"","su2020_track_ana_dar_11_1070");

    d  = Book->NewDataset ("su2020.cele0s61b1" ,"",-1,   1000000); 
    hf = Book->NewHistFile("su2020.cele0s61b1" ,"","su2020_track_ana_11_1070");
    hf = Book->NewHistFile("su2020.cele0s61b1" ,"","su2020_track_ana_12_1070");

    d  = Book->NewDataset ("su2020.cele0s61b2" ,"",-1,   1000000); 
    hf = Book->NewHistFile("su2020.cele0s61b2" ,"","su2020_track_ana_10_1070");

    d  = Book->NewDataset ("su2020.cosm0s71b0" ,"",-1,   1000000); // cluster included 
    hf = Book->NewHistFile("su2020.cosm0s71b0" ,"","su2020_cosmic_ana_dar"  );
    hf = Book->NewHistFile("su2020.cosm0s71b0" ,"","su2020_cosmic_ana_par"  );

    d  = Book->NewDataset ("su2020.cosm0s81b0" ,"",-1,   1000000); 
    hf = Book->NewHistFile("su2020.cosm0s81b0" ,"","su2020_cosmic_ana_dar"  );
    hf = Book->NewHistFile("su2020.cosm0s81b0" ,"","su2020_cosmic_ana_par"  );

    d  = Book->NewDataset ("su2020.cry31s71b0" ,"",-1,   1000000);            // cluster included 
    hf = Book->NewHistFile("su2020.cry31s71b0" ,"","su2020_cosmic_ana_dar"  );
    hf = Book->NewHistFile("su2020.cry31s71b0" ,"","su2020_cosmic_ana_par"  );

    d  = Book->NewDataset ("su2020.cry31s81b0" ,"",-1,   1000000); 
    hf = Book->NewHistFile("su2020.cry31s81b0" ,"","su2020_cosmic_ana_dar"  );
    hf = Book->NewHistFile("su2020.cry31s81b0" ,"","su2020_cosmic_ana_par"  );

    d  = Book->NewDataset ("su2020.ele00s51b0" ,"",-1,       1000000); // cluster included 
    hf = Book->NewHistFile("su2020.ele00s51b0" ,"","track_comp"      );
    hf = Book->NewHistFile("su2020.ele00s51b0" ,"","su2020_track_ana");

    d  = Book->NewDataset ("su2020.ele00s61b0" ,"",-1,       1000000);     // PID dataset
    hf = Book->NewHistFile("su2020.ele00s61b0" ,"","pid_emuana_1070");

    d  = Book->NewDataset ("su2020.ele00sx1b0" ,"",-1,   1000000 ); // no cluster in the track fit
    hf = Book->NewHistFile("su2020.ele00sx1b0" ,"","track_comp"  );

    d  = Book->NewDataset ("su2020.ele00sy0b0" ,"",-1,       10000   );
    hf = Book->NewHistFile("su2020.ele00sy0b0" ,"","su2020_track_ana");

    d  = Book->NewDataset ("su2020.ele00sz0b0" ,"",-1,       10000   );
    hf = Book->NewHistFile("su2020.ele00sz0b0" ,"","su2020_track_ana");

    d  = Book->NewDataset ("su2020.fele1s51b0" ,"",-1,   1000000); 
    hf = Book->NewHistFile("su2020.fele1s51b0" ,"","su2020_track_ana_dar_11_7"  );
    hf = Book->NewHistFile("su2020.fele1s51b0" ,"","su2020_track_ana_par_11_7"  );

    d  = Book->NewDataset ("su2020.fele2s51b1" ,"",-1,   10000000); 
    hf = Book->NewHistFile("su2020.fele2s51b1" ,"","su2020_track_ana_12_1070");

    d  = Book->NewDataset ("su2020.flsh0s11b0" ,"",-1,   2500000); 
    hf = Book->NewHistFile("su2020.flsh0s11b0" ,"","spmc_ana"  );

    d  = Book->NewDataset ("su2020.flsh1s11b0" ,"",-1,   2500000); 
    hf = Book->NewHistFile("su2020.flsh1s11b0" ,"","spmc_ana"  );

    d  = Book->NewDataset ("su2020.mbs00s11b1" ,"",-1,   200); 
    hf = Book->NewHistFile("su2020.mbs00s11b1" ,"","straw_hit_ana"  );

    d  = Book->NewDataset ("su2020.mumi0s61b0" ,"",-1,  1000000);     // PID dataset
    hf = Book->NewHistFile("su2020.mumi0s61b0" ,"","pid_emuana");

    d  = Book->NewDataset ("su2020.pbar0s11b0" ,"",-1,2000000000); // Giovanni pbars at VD91
    hf = Book->NewHistFile("su2020.pbar0s11b0" ,"","spmc_ana"    );

    d  = Book->NewDataset ("su2020.su_stntuple_p1_000_ele00" ,"",-1,   10000); 
    hf = Book->NewHistFile("su2020.su_stntuple_p1_000_ele00" ,"","su2020_track_ana_par"  );
  }
}

#endif
