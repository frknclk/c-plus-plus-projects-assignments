#include <string>
#include <iostream>
#include <fstream>
#include<iomanip>
#include<cmath>
using namespace std;

int main () {
	cout << "Ax=B isleminde A ve B yi .txt dosyalarindan cekip X i Gauss Elimination metodu ile yazdiracagiz \n" ;
  fstream Amatrix("A.txt");
  fstream Bmatrix("b.txt");
  ofstream Xmatrix;
  int rowofA=0;
  int rowofB=0;
  
  if (Amatrix.is_open())
  {
  	string line;
    while ( getline (Amatrix,line) )
    {
      rowofA++;
    }
    Amatrix.close();
  }
  else {cout<< "Unable to read.";
  }
  
  double** A;
  A=new double* [rowofA];
 
  
  for(int i=0;i<rowofA;i++){
  	A[i] = new double [rowofA];
  }
  
 
  Amatrix.open ("A.txt");

  	int i=0,j=0;
  	for(i=0;i<rowofA;i++){
  		for(j=0;j<rowofA;j++){
  			Amatrix >> A[i][j];
            
		  }
		  
	  }
	  Amatrix.close();
	  cout << "A matrix =  \n";
  	for(i=0;i<rowofA;i++){
  		for(j=0;j<rowofA;j++){
  			
            cout << A [i] [j] << " ";
		  }
		  cout << "\n";
	  }
	    cout<< "A nin satir sayisi = "<< rowofA << "\n";
  if (Bmatrix.is_open()){
  	string line;
    while ( getline (Bmatrix,line) )
    {
      rowofB++;
    }
    Bmatrix.close();
  }
  else {cout<< "Unable to read.";
  }
   double** B;
  B=new double* [rowofB];
  
  for(int i=0;i<rowofB;i++){
  	B[i] = new double [rowofB];
  }
  
   Bmatrix.open ("b.txt");

  	for(int k=0; k<rowofB;k++){
  		
  			Bmatrix >> B[k][0];
            	  
	  }
	  Bmatrix.close();
	  cout << "B matrix =  \n";
  	for(int k=0;k<rowofB;k++){
  		
  			
            cout << B [k] [0] << "\n";
	}

	cout << "\n B nin satir sayisi = " << rowofB << "\n------------------------------------------------------------------------\n";
	
	
	
	for (int a=0; a<rowofA; a++){
		
		for(int b=a+1; b<rowofB; b++){
		
			double t = A[b][a]/A[a][a];
				B[b][0]=B[b][0]-t*B[a][0];
				for (int c=0; c<rowofB; c++){
					A[b][c]=A[b][c]-t*A[a][c];  //elimination
				}
	 
		}
	}
	// eliminated n by n A matrix = U
	 double ** U;
  U=new double* [rowofA];
  for (int i=0; i<rowofA; i++){
  	U[i]=new double [rowofA];
  }
	
	for (int a=0; a<rowofA; a++){
		for (int b=0; b<rowofB; b++){
			U[a][b] = A[a][b] ;
		}
	
	}
	cout << "(eliminated matrix A) U matrix= \n";
		for (int a=0; a<rowofA; a++){
		for (int b=0; b<rowofB; b++){
		 cout <<U[a][b] << " ";
		}
	cout<< "\n";
	}
	cout << "\n new B matrix = \n" ;

	for (int a=0; a<rowofB; a++){
		cout<<B[a][0]<<"\n";
	}
	//-------------------------------x matrix----------------------------
		
  double** X;
  X=new double* [rowofA];
  
  for(int i=0;i<rowofA;i++){
  	X[i] = new double [rowofA];
  }
	//----------------------------------------------------------
		double sum;
		for (int a=rowofA-1; a>=0; a--){
		sum=0;
		for (int b=rowofA-1; b>=0; b--){
			sum=sum+(U[a][b]*X[b][0]);
		} 
	
		X[a][0]=(B[a][0]-sum)/U[a][a];
		
	} 
	cout << "X Matrix =  \n";
	
		
	  Xmatrix.open ("x.txt");
	  
		for (int a=0; a<rowofA; a++){
			cout << "x"<<a+1<<" = "<< X[a][0] << "\n";
			Xmatrix << "x"<<a+1<<" = "<< X[a][0] << "\n";
		}
	
	 
	  Xmatrix.close (); 
	  
  return 0;
}
