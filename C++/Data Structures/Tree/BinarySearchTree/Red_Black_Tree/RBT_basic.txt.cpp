Red Black tree
===============
- Every Node is either Red or Black 
- Root is always black
- No two consecutive Reds i.e parent and child cannot be Red 
- When you traverse or travel from root to the leaf the number of black should be same or Black heights should be same 


 AVL is strict in terms of height but RBT is not 

 -Insertion and Deletion is faster in RBT hence it is used in STL ( Standard Template Library) but searching in AVL is faster 
 
 - In RBT we use coloring and Rotation to meet the standard rules of RBT 
 

 LL Case :
 =========
                      Z 
				   Y     T1
				 X   T2
				 
				 
	if(color of Y is  not black) 		
    if(T1 is also Red)   
		Then change the color of Y as black
		Then change the color of Z as Red
  
  Case :1
  ========
  Ex : 
  
      