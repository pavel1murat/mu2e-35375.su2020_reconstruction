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
  stn_dataset_t* ds;
  hist_file_t*   hf;
//-----------------------------------------------------------------------------
// the best way to manage multiple datasets is to arrange them alphabetically
//-----------------------------------------------------------------------------
  if (strcmp(Book->Name(),"mdc2020") == 0) {
    ds = Book->NewDataset ("mdc2020.no-primary-mix-d"  ,"",-1,1000);
    hf = Book->NewHistFile("mdc2020.no-primary-mix-d" ,"","straw_hit_ana");
  }
  else if (strcmp(Book->Name(),"su2020") == 0) {
    ds = Book->NewDataset ("su2020.cele0s51b0" ,"",-1,   1000000); 
    hf = Book->NewHistFile("su2020.cele0s51b0" ,"","su2020_track_ana_dar_11_1070"  );

    ds = Book->NewDataset ("su2020.cele0s51b1" ,"",-1,   1000000); 
    hf = Book->NewHistFile("su2020.cele0s51b1" ,"","su2020_track_ana_dar_11_1070");
    hf = Book->NewHistFile("su2020.cele0s51b1" ,"","pid_emuana");

    ds = Book->NewDataset ("su2020.cele0s51b2" ,"",-1,   1000000); 
    hf = Book->NewHistFile("su2020.cele0s51b2" ,"","track_comp_use_mva_ffff_1070");
    hf = Book->NewHistFile("su2020.cele0s51b2" ,"","su2020_track_ana_dar_11_1070");

    ds = Book->NewDataset ("su2020.cele0s61b1" ,"",-1,   1000000); 
    hf = Book->NewHistFile(ds->id()            ,"","pid_emuana_1012");

    ds = Book->NewDataset ("su2020.cele0s61b2" ,"",-1,   1000000); 
    hf = Book->NewHistFile(ds->id()            ,"","su2020_track_ana_10_1070");
    hf = Book->NewHistFile(ds->id()            ,"","su2020_track_ana_11_1070");
    hf = Book->NewHistFile(ds->id()            ,"","su2020_track_ana_12_1070");
    hf = Book->NewHistFile(ds->id()            ,"","su2020_track_ana_1010");
    hf = Book->NewHistFile(ds->id()            ,"","pid_emuana_1010");

    ds = Book->NewDataset ("su2020.cosm0s71b0" ,"",-1,   1000000); // cluster included 
    hf = Book->NewHistFile("su2020.cosm0s71b0" ,"","su2020_cosmic_ana_dar"  );
    hf = Book->NewHistFile("su2020.cosm0s71b0" ,"","su2020_cosmic_ana_par"  );

    ds = Book->NewDataset ("su2020.cosm0s81b0" ,"",-1,   1000000); 
    hf = Book->NewHistFile("su2020.cosm0s81b0" ,"","su2020_cosmic_ana_dar"  );
    hf = Book->NewHistFile("su2020.cosm0s81b0" ,"","su2020_cosmic_ana_par"  );

    ds = Book->NewDataset ("su2020.cry31s71b0" ,"",-1,   1000000);            // cluster included 
    hf = Book->NewHistFile("su2020.cry31s71b0" ,"","su2020_cosmic_ana_dar"  );
    hf = Book->NewHistFile("su2020.cry31s71b0" ,"","su2020_cosmic_ana_par"  );

    ds = Book->NewDataset ("su2020.cry31s81b0" ,"",-1,   1000000); 
    hf = Book->NewHistFile("su2020.cry31s81b0" ,"","su2020_cosmic_ana_dar"  );
    hf = Book->NewHistFile("su2020.cry31s81b0" ,"","su2020_cosmic_ana_par"  );

    ds = Book->NewDataset ("su2020.ele00s51b0" ,"",-1,       1000000); // cluster included 
    hf = Book->NewHistFile("su2020.ele00s51b0" ,"","track_comp"      );
    hf = Book->NewHistFile("su2020.ele00s51b0" ,"","su2020_track_ana");

    ds = Book->NewDataset ("su2020.ele00s61b0" ,"",-1,       1000000);     // PID dataset
    hf = Book->NewHistFile("su2020.ele00s61b0" ,"","pid_emuana_1070");
    hf = Book->NewHistFile("su2020.ele00s61b0" ,"","pid_emuana_1010");
    hf = Book->NewHistFile("su2020.ele00s61b0" ,"","su2020_track_ana_1010");   // 1000(DAR) + 10(on the fly)
    hf = Book->NewHistFile("su2020.ele00s61b0" ,"","su2020_mva_test_dar_0170");
    hf = Book->NewHistFile("su2020.ele00s61b0" ,"","su2020_mva_test_dar_1070");

    ds = Book->NewDataset ("su2020.ele00sx1b0" ,"",-1,   1000000 ); // no cluster in the track fit
    hf = Book->NewHistFile("su2020.ele00sx1b0" ,"","track_comp"  );

    ds = Book->NewDataset ("su2020.ele00sy0b0" ,"",-1,       10000   );
    hf = Book->NewHistFile("su2020.ele00sy0b0" ,"","su2020_track_ana");

    ds = Book->NewDataset ("su2020.ele00sz0b0" ,"",-1,       10000   );
    hf = Book->NewHistFile("su2020.ele00sz0b0" ,"","su2020_track_ana");

    ds = Book->NewDataset ("su2020.ele01s51b0" ,"",-1,       1000000);     // PID dataset
    hf = Book->NewHistFile(ds->id()            ,"","su2020_track_ana_1110");

    ds = Book->NewDataset ("su2020.fele1s51b0" ,"",-1,   1000000); 
    hf = Book->NewHistFile("su2020.fele1s51b0" ,"","su2020_track_ana_dar_11_7"  );
    hf = Book->NewHistFile("su2020.fele1s51b0" ,"","su2020_track_ana_par_11_7"  );

    ds = Book->NewDataset ("su2020.fele2s51b1" ,"",-1,   10000000); 
    hf = Book->NewHistFile("su2020.fele2s51b1" ,"","su2020_track_ana_12_1070");

    ds = Book->NewDataset ("su2020.flsh0s11b0" ,"",-1,   2500000); 
    hf = Book->NewHistFile("su2020.flsh0s11b0" ,"","spmc_ana"  );

    ds = Book->NewDataset ("su2020.flsh1s11b0" ,"",-1,   2500000); 
    hf = Book->NewHistFile("su2020.flsh1s11b0" ,"","spmc_ana"  );

    ds = Book->NewDataset ("su2020.mbs00s11b1" ,"",-1,   200); 
    hf = Book->NewHistFile("su2020.mbs00s11b1" ,"","straw_hit_ana"  );

    ds = Book->NewDataset ("su2020.mumi0s61b0" ,"",-1,  1000000);     // PID dataset 105 MeV/c
    hf = Book->NewHistFile(ds->id()            ,"","pid_emuana");
    hf = Book->NewHistFile(ds->id()            ,"","pid_emuana_1010");
    hf = Book->NewHistFile(ds->id()            ,"","su2020_track_ana_10_1070");
    hf = Book->NewHistFile(ds->id()            ,"","su2020_track_ana_1010");

    ds = Book->NewDataset ("su2020.mupl3s51b0" ,"",-1,  1000000);     // 
    hf = Book->NewHistFile(ds->id()            ,"","su2020_track_ana_00_ffff");
    hf = Book->NewHistFile(ds->id()            ,"","su2020_track_ana_10_ffff");

    ds = Book->NewDataset ("su2020.mumi1s51b0" ,"",-1,  1000000);     // PID dataset 92.32 MeV/c
    hf = Book->NewHistFile(ds->id()            ,"","su2020_track_ana_10_1170");

    ds = Book->NewDataset ("su2020.mupl0s51b0" ,"",-1,  1000000);     // PID dataset
    hf = Book->NewHistFile(ds->id()            ,"","su2020_track_ana_10_1170");

    ds = Book->NewDataset ("su2020.mupl1s51b0" ,"",-1,  1000000);     // PID dataset
    hf = Book->NewHistFile(ds->id()            ,"","pid_emuana_1110");
    hf = Book->NewHistFile(ds->id()            ,"","su2020_track_ana_1110");

    ds = Book->NewDataset ("su2020.pbar0s11b0" ,"",-1,2000000000); // Giovanni pbars at VD91
    hf = Book->NewHistFile(ds->id()            ,"","spmc_ana"    );

    ds = Book->NewDataset ("su2020.pos00s51b0" ,"",-1,   1000000); 
    hf = Book->NewHistFile(ds->id()            ,"","su2020_mva_test_dar_1070");

    ds = Book->NewDataset ("su2020.pos01s51b0" ,"",-1,   1000000); 
    hf = Book->NewHistFile(ds->id()            ,"","pid_emuana_1110");
    hf = Book->NewHistFile(ds->id()            ,"","su2020_track_ana_1110");

    ds = Book->NewDataset ("su2020.su_stntuple_p1_000_ele00" ,"",-1,   10000); 
    hf = Book->NewHistFile(ds->id()                          ,"","su2020_track_ana_par"  );

    ds = Book->NewDataset ("su2020.su_stntuple_p02_dar_002_ele00","",-1,   10000); 
    hf = Book->NewHistFile(ds->id()                              ,"","pid_emuana"  );

    ds = Book->NewDataset ("su2020.su_stntuple_p02_dar_003_ele00","",-1,   10000); 
    hf = Book->NewHistFile(ds->id()                              ,"","pid_emuana"  );

    ds = Book->NewDataset ("su2020.su_stntuple_p02_dar_009_ele00","",-1,   10000); 
    hf = Book->NewHistFile(ds->id()                              ,"","pid_emuana"  );
  }
}

#endif
