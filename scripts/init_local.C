///////////////////////////////////////////////////////////////////////////////
// MC datasets for the vertical beam scan
///////////////////////////////////////////////////////////////////////////////
#ifndef __init_local_datasets__
#define __init_local_datasets__

#include "Stntuple/scripts/stn_dataset.hh"
#include "Stntuple/scripts/stn_book.hh"

//-----------------------------------------------------------------------------
// get histogram file for a given dataset ID
//-----------------------------------------------------------------------------
hist_file_t* hist_data_t::get_hist_file(const char* DsID, const char* JobName) {
  printf("[get_hist_file]: dsid: %s  job: %s fBook = %p\n",DsID,JobName,fBook);
  
  hist_file_t* hf = fBook->FindHistFile(DsID,"",JobName);
  
  if (hf == nullptr) {
    printf(" get_hist_file ERROR: cant find hist file for dsid=%s, job=%s; return NULL\n",
	   DsID,JobName);
  }
  return hf;
}

//-----------------------------------------------------------------------------
// get dataset by the dataset ID
// intention - to hide the dataset/book internals from init_local_hist_files.C
//-----------------------------------------------------------------------------
stn_dataset_t* get_dataset(stn_book* Book, const char* DsID) {
  stn_dataset_t* d = Book->FindDataset(DsID);
  return d;
}

//-----------------------------------------------------------------------------
void init_local(stn_book* Book) {
  stn_dataset_t* d;
  hist_file_t*   hf;
//-----------------------------------------------------------------------------
// 
//-----------------------------------------------------------------------------
  if (strcmp(Book->Name(),"mdc2020") == 0) {
    d  = Book->NewDataset ("mdc2020.no-primary-mix-d"  ,"",-1,1000);
    hf = Book->NewHistFile("mdc2020.no-primary-mix-d" ,"","straw_hit_ana");
  }
  else if (strcmp(Book->Name(),"su2020") == 0) {
    d  = Book->NewDataset ("su2020.pbar0s11b0" ,"",-1,2000000000); // Giovanni pbars at VD91
    hf = Book->NewHistFile("su2020.pbar0s11b0" ,"","spmc_ana"    );

    d  = Book->NewDataset ("su2020.ele00s51b0" ,"",-1,       1000000); // cluster included 
    hf = Book->NewHistFile("su2020.ele00s51b0" ,"","track_comp"      );
    hf = Book->NewHistFile("su2020.ele00s51b0" ,"","su2020_track_ana");

    d  = Book->NewDataset ("su2020.ele00sx1b0" ,"",-1,   1000000 ); // no cluster in the track fit
    hf = Book->NewHistFile("su2020.ele00sx1b0" ,"","track_comp"  );

    d  = Book->NewDataset ("su2020.ele00sy0b0" ,"",-1,       10000   );
    hf = Book->NewHistFile("su2020.ele00sy0b0" ,"","su2020_track_ana");

    d  = Book->NewDataset ("su2020.ele00sz0b0" ,"",-1,       10000   );
    hf = Book->NewHistFile("su2020.ele00sz0b0" ,"","su2020_track_ana");

    d  = Book->NewDataset ("su2020.cele0s51b0" ,"",-1,   1000000); 
    hf = Book->NewHistFile("su2020.cele0s51b0" ,"","su2020_conv_ana_dar"  );
    hf = Book->NewHistFile("su2020.cele0s51b0" ,"","su2020_conv_ana_par"  );
    hf = Book->NewHistFile("su2020.cele0s51b0" ,"","su2020_track_ana_dar_11_2"  );
    hf = Book->NewHistFile("su2020.cele0s51b0" ,"","su2020_track_ana_par_11_2"  );
    hf = Book->NewHistFile("su2020.cele0s51b0" ,"","track_ana"  );

    d  = Book->NewDataset ("su2020.cosm0s71b0" ,"",-1,   1000000); // cluster included 
    hf = Book->NewHistFile("su2020.cosm0s71b0" ,"","su2020_cosmic_ana_dar"  );
    hf = Book->NewHistFile("su2020.cosm0s71b0" ,"","su2020_cosmic_ana_par"  );

    d  = Book->NewDataset ("su2020.cosm0s81b0" ,"",-1,   1000000); 
    hf = Book->NewHistFile("su2020.cosm0s81b0" ,"","su2020_cosmic_ana_dar"  );
    hf = Book->NewHistFile("su2020.cosm0s81b0" ,"","su2020_cosmic_ana_par"  );
    hf = Book->NewHistFile("su2020.cosm0s81b0" ,"","su2020_track_ana_par"  );

    d  = Book->NewDataset ("su2020.cry31s71b0" ,"",-1,   1000000);            // cluster included 
    hf = Book->NewHistFile("su2020.cry31s71b0" ,"","su2020_cosmic_ana_dar"  );
    hf = Book->NewHistFile("su2020.cry31s71b0" ,"","su2020_cosmic_ana_par"  );

    d  = Book->NewDataset ("su2020.cry31s81b0" ,"",-1,   1000000); 
    hf = Book->NewHistFile("su2020.cry31s81b0" ,"","su2020_cosmic_ana_dar"  );
    hf = Book->NewHistFile("su2020.cry31s81b0" ,"","su2020_cosmic_ana_par"  );

    d  = Book->NewDataset ("su2020.su_stntuple_p1_000_ele00" ,"",-1,   10000); 
    hf = Book->NewHistFile("su2020.su_stntuple_p1_000_ele00" ,"","su2020_track_ana_par"  );

    d  = Book->NewDataset ("su2020.fele1s51b0" ,"",-1,   1000000); 
    hf = Book->NewHistFile("su2020.fele1s51b0" ,"","su2020_track_ana_dar_11_7"  );
    hf = Book->NewHistFile("su2020.fele1s51b0" ,"","su2020_track_ana_par_11_7"  );

    d  = Book->NewDataset ("su2020.flsh0s11b0" ,"",-1,   2500000); 
    hf = Book->NewHistFile("su2020.flsh0s11b0" ,"","spmc_ana"  );

    d  = Book->NewDataset ("su2020.flsh1s11b0" ,"",-1,   2500000); 
    hf = Book->NewHistFile("su2020.flsh1s11b0" ,"","spmc_ana"  );

    d  = Book->NewDataset ("su2020.mbs00s11b1" ,"",-1,   200); 
    hf = Book->NewHistFile("su2020.mbs00s11b1" ,"","straw_hit_ana"  );
  }
}

#endif
