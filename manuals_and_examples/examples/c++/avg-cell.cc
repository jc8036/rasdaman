/*
* This file is part of rasdaman community.
*
* Rasdaman community is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Rasdaman community is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with rasdaman community.  If not, see <http://www.gnu.org/licenses/>.
*
* Copyright 2003, 2004, 2005, 2006, 2007, 2008, 2009 Peter Baumann /
rasdaman GmbH.
*
* For more information please see <http://www.rasdaman.org>
* or contact Peter Baumann via <baumann@rasdaman.com>.
*/
/*************************************************************
 *
 *
 * PURPOSE: 
 * Example program for computing the avg cell value 
 * for each n-D 8-bit grey image in a given collection.
 *
 *
 ************************************************************/

#include <iostream>

// Linux needs this for template instantiation
#ifdef EARLY_TEMPLATE
#define __EXECUTABLE__
#ifdef __GNUG__
#include "raslib/template_inst.hh"
#endif
#endif

// rasdl generated data type file:
// (contains predefined RGBPixel structure)
#include "basictypes.hh"


int main( int ac, char** av )
{   
  char rasmgrName[255];
  int  rasmgrPort;
  char baseName[255];
  char collName[255];
  char userName[255];
  char userPass[255];
  r_Base_Type *celltype;
  double sum;
   
  if( ac != 7 )
  {
    cout << "Usage: avg-cell rasmgr_name rasmgr_port base_name collection_name user_name user_passwd" << endl;
    return -1;
  }

  strcpy( rasmgrName, av[1] );
  rasmgrPort = strtoul( av[2], NULL, 0);
  strcpy( baseName,   av[3] );
  strcpy( collName,   av[4] );
  strcpy( userName,   av[5] );
  strcpy( userPass,   av[6] );

  r_Database                           database;
  r_Transaction                        transaction;
  r_Ref< r_Set< r_Ref< r_Marray< RGBPixel > > > > image_set; 
  r_Iterator< r_Ref< r_Marray< RGBPixel > > > iter;
  r_Ref< r_Marray< RGBPixel > >               image;
  r_Range                              i;

  try
  {
    database.set_servername( rasmgrName, rasmgrPort );
    database.set_useridentification( userName, userPass );
  
    cout << "Opening database " << baseName
         << " on " << rasmgrName << "... " << flush;
    database.open( baseName );
    cout << "OK" << endl;
  
    cout << "Starting read-only transaction ... " << flush;
    transaction.begin( r_Transaction::read_only );
    cout << "OK" << endl;
  
    cout << "Looking up collection " << collName << " ..." << flush;
    image_set = database.lookup_object( collName );
    cout << "OK" << endl;
 
    cout << "Collection contains " << image_set->cardinality() 
         << " entries" << endl;

    iter = image_set->create_iterator();
    for( iter.reset(); iter.not_done(); iter++ )
    {
      image = *iter;
      if ( image->get_type_length() != 1 )
        cout << "skipping image because of non-int cell type" << endl;
      else
      {
        unsigned char *pixelfield = (unsigned char*) image->get_array();
        sum = 0.0;
        for ( i=0; i < image->get_array_size(); i++ )
          sum += pixelfield[i];
        cout << "  avg over " << image->get_array_size() 
             << " pixels is " << sum/image->get_array_size() << endl;   
      }
    }  

    cout << "Committing transaction ... " << flush;
    transaction.commit();
    cout << "OK" << endl;
  
    cout << "Closing database ... " << flush;
    database.close();
    cout << "OK" << endl;
  }
  catch( r_Error& errorObj )
  {
    cerr << errorObj.what() << endl;
    return -1;
  }
    
  return 0;
}

/* 
 * end of avg-cell.cc
 */