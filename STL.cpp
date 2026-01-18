 /////////////////////////////////////////////////////////////
//      Generalised Data Structure Library Project
//////////////////////////////////////////////////////////////

/*
---------------------------------------------------------------------------------------
Type                    Name of class for node      Name of class for Functionality
---------------------------------------------------------------------------------------
Singly Linear            SinglyLLLnode               SinglyLLL          Done
Singly Cirular           SinglyCLLnode               SinglyCLL          Done
Doubly Linear            DoublyLLLnode               DoublyLLL          Done
Doubly Circular          DoublyCLLnode               DoublyCLL          Done
Stack                    Stacknode                   Stack              Done
Queue                    Queuenode                   Queue              Done
---------------------------------------------------------------------------------------
*/

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//          Singly Linear LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template<class T>
class SinglyLLL
{
    private:        
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);
};

template<class T>
SinglyLLL<T> :: SinglyLLL()
{
    cout<<"Object of SinglyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  InsertFirst
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to insert node at first position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  06/01/2026
//
/////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLLL<T> :: InsertFirst(T no)
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  InsertLast
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to insert node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  016/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T> ::InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    this->iCount++;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteFirst
//  Input         :  Delete Data of node
//  Output        :  nothing
//  Description   :  Used to Dekete node at first position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T> ::DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;
        delete temp;
    }

    this->iCount--;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T> ::DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)  
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  Display
//  Input         :  Number of Data  node
//  Output        :  Dispaly the total Number of Nodes 
//  Description   :  Used to insert node at first position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T> ::Display()
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  Count
//  Input         :  Count the total Number of Nodes
//  Output        :  Count Number 
//  Description   :  Used to Count Number of nodes
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyLLL<T> ::Count()
{
    return this->iCount;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  InsertAtPos
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to insert node at  position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T> ::InsertAtPos(T no, int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteAtPos
//  Input         :  Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyLLL<T> ::DeleteAtPos(int pos)
{
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
//          Doubly Linear LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode *next;
        DoublyLLLnode *prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template<class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;
        int iCount;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout<<"Linked List gets created\n";

    this->first = NULL;
    this->iCount = 0;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> ::InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    
    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> ::InsertLast(T no) 
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;    
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> ::InsertAtPos(T no,int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;

    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }  

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> ::DeleteFirst()
{
    if(this->first == NULL)                 // LL is empty
    {
        return;
    }
    else if(this->first->next == NULL)      // LL contains 1 node
    {
        delete this->first;
        this->first = NULL;
    }
    else                                    // LL contains more than 1 node
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> ::DeleteLast()
{
    DoublyLLLnode<T> *temp = NULL;

    if(this->first == NULL)                 // LL is empty
    {
        return;
    }
    else if(this->first->next == NULL)      // LL contains 1 node
    {
        delete this->first;
        this->first = NULL;
    }
    else                                    // LL contains more than 1 node
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;    
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> ::DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if((pos < 1) || (pos > this->iCount))
    {
        cout<<"Invalid position\n";
        return;
    }  

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }    
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void DoublyLLL<T> ::Display()
{
    DoublyLLLnode<T> *temp = NULL;
    
    temp = this->first;

    cout<<"\nNULL<=>";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
int DoublyLLL<T> ::Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////
//          Singly Circuler Linear LinlkedList using Generic Approach
///////////////////////////////////////////////////////////////////////
#pragma pack(1)
template<class T>
class SinglyCLLnode
{
    public:
    T data;
    SinglyCLLnode<T> *next;
     SinglyCLLnode(T no)
    {
       this->data = no;
       this->next = NULL;
    }

};
template<class T>
class SinglyCLL
{
   private:
      SinglyCLLnode<T> * first;
      SinglyCLLnode<T> * last;
      int iCount;

    public  :
    SinglyCLL();
       void InsertFirst(T);
      void InsertLast(T);
      void DeleteFirst();
      void DeleteLast();
      void Display();
       int Count();
       void InsertAtPos(T, int);
       void DeleteAtPos(int);
        
};
template<class T>
SinglyCLL<T>::SinglyCLL()
{
cout<<"object of SinglyCL Gets created.\n";
this-> first = NULL;
this-> last = NULL;
this->iCount = 0;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T>:: InsertFirst(T no)
{
SinglyCLLnode <T> * newn = NULL;
 newn = new SinglyCLLnode<T>(no);
if((this->first == NULL)&&(this->last == NULL))

{
  this->first = newn;
  this->last = newn;
  
}
else
{
  newn->next = this->first;
  this->first = newn;
}
last->next = this->first;
this->iCount++;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T>:: InsertLast(T no)
{
SinglyCLLnode<T> * newn = NULL;
 newn = new SinglyCLLnode<T>(no);
if((this->first == NULL)&&(this->last == NULL))

{
  this->first = newn;
  this->last = newn;
  
}
else
{
    this->last->next = newn;
    this->last = newn;
}
this->last->next = first;
this->iCount++;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T>:: DeleteFirst()
{
SinglyCLLnode<T> * temp = NULL;
if((first == NULL)&&(last == NULL))
{
return;
}
else if(this->first == this->last)
{
delete this->first;
this->first = NULL;
this->last = NULL;
}
else
{
    temp = this->first;
    this->first = this->first->next;
    delete temp;
    this->last->next = this->first;
    
}
this->iCount--;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T>:: DeleteLast()
{
SinglyCLLnode<T> *temp = NULL;
if((this->first == NULL)&&(this->last == NULL))
{
return;
}
else if(this->first == this->last)
{
delete this->first;
this->first = NULL;
this->last = NULL;
}
else
{
temp  = this->first;
while(temp->next != this->last)
{
  temp = temp->next;
}   
delete this->last;
this->last = temp;
this->last->next = this->first; 
}
this->iCount--;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T>:: Display()
{
do  
{
printf("|%d|->",this->first->data);
this->first  = this->first->next;
}while(this->first != this->last->next);
printf("\n");

}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
int SinglyCLL<T>:: Count()
{
return this->iCount;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T>:: InsertAtPos(T no, int pos)
{
int iCnt = 0;
SinglyCLLnode<T> * newn = NULL;
SinglyCLLnode<T> * temp = NULL;
if((pos <1)||(pos>this->iCount+1))
{
cout<<"Invalid Position\n";
return;
}
if(pos == 1)
{
this->InsertFirst(no);
}
else if(pos == this->iCount+1)
{
this->InsertLast(no);
}
else
{
   newn = new SinglyCLLnode<T>(no);
   temp = this->first;
  for(iCnt = 1; iCnt<pos-1; iCnt++)
  {
  temp = temp->next;
  }
  newn->next = temp->next;
  temp->next = newn;
  this->iCount++;

}

}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void SinglyCLL<T>:: DeleteAtPos(int pos)
{
int iCnt = 0;
SinglyCLLnode<T> * temp = NULL;
SinglyCLLnode<T> * target = NULL;
if((pos <1)||(pos>this->iCount))
{
cout<<"Invalid Position\n";
return;
}
if(pos == 1)
{
this->DeleteFirst();
}
else if(pos == iCount)
{
this->DeleteLast();
}
else
{
temp = this->first;

for(iCnt = 1; iCnt<pos-1; iCnt++)
{
    temp = temp->next;

}
target = temp->next;
temp->next = target->next;
delete target;
this->iCount--;
}
}
// /////////////////////////////////////////////////////////////////
// Doubly Circuler Linear LinlkedList using Generic Approach
//////////////////////////////////////////////////////////////////////
 #include <iostream>
using namespace std;
#pragma pack (1) 
template <class T>
class DoublyCLLnode
{
    public:
    T data;
     DoublyCLLnode<T> *next;
     DoublyCLLnode<T> *prev;
        DoublyCLLnode<T> (T no)
        {
             this->data = no;
             this->next = NULL;
             this->prev = NULL;

        }
};
template <class T>
class DoublyCLL
{
private:
     DoublyCLLnode<T> *first;
     DoublyCLLnode<T> *last;
    int iCount;

public:
    DoublyCLL();
    void InsertFirst(T);
    void InsertLast(T);
    void DeleteFirst();
    void DeleteLast();
    void Display();
    int Count();
    void DeleteAtPos( T);
    void InsertAtPos(T, T pos);
};
template <class T>
DoublyCLL<T>::DoublyCLL()
{
    cout << "object of DoublyCLL Gets created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
     DoublyCLLnode<T> *newn = NULL;
     newn = new DoublyCLLnode<T>(no);
    if(this->first == NULL && this->last == NULL)
    {
        this->first = this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->first->prev = this->last;
    this->last->next = this->first;
    this->iCount++;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
     DoublyCLLnode<T> *newn = NULL;
     newn = new DoublyCLLnode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last;
    this->iCount++;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    DoublyCLLnode<T> * temp = NULL;
    if((this->first == NULL) && (this->last == NULL))
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete temp;

        this->first->prev = this->last;
        this->last->next = this->first;
    }
    this->iCount--;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteLast()
{
    DoublyCLLnode<T> * temp = NULL;
    if((this->first == NULL) && (this->last == NULL))
    {
        return;

    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->last;
        this->last = this->last->prev;
        delete temp;

        this->last->next = this->first;
        this->first->prev = this->last;
    }
    this->iCount--;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::Display()
{
      if((this->first == NULL) && (this->last == NULL))
    {
        
        return;
    }

    DoublyCLLnode<T> *temp = this->first;
     do
    {
        printf("|%d|<->", temp->data);
        temp = temp->next;
    }while(temp != this->first);
         printf("\n");
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::Count()
{
    return this->iCount;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteAtPos(T pos)
{
    int iCnt = 0;
    DoublyCLLnode<T> * temp = NULL;
    if((pos < 1) || (pos > this->iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if(pos == 1)
        this->DeleteFirst();
    else if(pos == iCount)
        this->DeleteLast();
    else
    {
           temp = this->first;
        for(iCnt = 1; iCnt < pos; iCnt++)
        {
             
            temp = temp->next;
        } 

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        this->iCount--;
    }
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertAtPos(T no, T pos)
{
    int iCnt = 0;
    DoublyCLLnode<T> * newn = NULL;
    DoublyCLLnode<T> *temp= NULL;
    if((pos < 1) || (pos > this->iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if(pos == 1)
        this->InsertFirst(no);
    else if(pos == this->iCount + 1)
        this->InsertLast(no);
    else
    {
        newn = new DoublyCLLnode<T>(no);
        temp = this->first;
        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
             temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        this->iCount++;
    }
}
///////////////////////////////////////////////////////////////////////
//          Stack using Generic Approach
///////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Stacknode
{
    public:
     T data;
     Stacknode<T> *next;

     Stacknode( T no)
     {
        this->data = no;
        this->next = NULL;
     }
};
template<class T>
class Stack
{
    private:
    Stacknode<T> *first;
    int iCount;

    public:
       Stack();

       void push(T);  
       T  pop();     
       T peep();
       void Display();
       int Count();
};
template<class T>
Stack<T>::Stack()
{
      cout<<"Stack gets created Succesfully..\n";
      this->first = NULL;
      this->iCount = 0;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void Stack<T>:: push(T no)
{
     Stacknode<T> *newn = NULL;
     newn = new Stacknode<T>(no);

     newn->next = this->first;
     this->first = newn;

     this->iCount++;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
T Stack<T>:: pop() 
{
      T Value = 0;
       Stacknode<T> *temp = this->first;
      if(this->first == NULL)
      {
         cout<<"Stack is Empty\n";
         return -1;
      }
      Value= this->first->data;
      this->first = this->first->next;
      delete temp;
      this->iCount--;
      return Value;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>    
T Stack<T>:: peep()
{
    T Value = 0;

      if(this->first == NULL)
      {
         cout<<"Stack is Empty\n";
         return -1;
      }
      Value= this->first->data;
      return Value;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void Stack<T>:: Display()
{
    Stacknode<T> *temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }
    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }

}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
int Stack<T>:: Count()
{
   return this->iCount;
}

///////////////////////////////////////////////////////////////////////
//          Queue using Generic Approach
///////////////////////////////////////////////////////////////////////
#pragma pack(1)
template<class T>
class Queuenode
{
    public:
     T data;
      Queuenode<T> *next;

     Queuenode(T no)
     {
        this->data = no;
        this->next = NULL;
     }
};
template<class T>
class Queue
{
    private:
   Queuenode<T> *first;
   Queuenode<T> *last;
    int iCount;

    public:
       Queue();

       void enqueue(T); 
       T  dequeue(); 
       void Display();
       int Count();
};
template<class T>
  Queue<T>::  Queue()
{
      cout<<" Queue gets created Succesfully..\n";
      this->first = NULL;
      this->last = NULL;
      this->iCount = 0;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
void  Queue<T>:: enqueue(T no)
{
     Queuenode<T> *newn = NULL;
     newn = new Queuenode<T>(no);
     if(this->first == NULL && this->last == NULL)
     {
        this->first = newn;
        this->last = newn;
     }
     else
     {
           this->last->next = newn;
           this->last = newn;
      
     }
     this->iCount++;

      
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
T Queue<T>:: dequeue() 
{
      T Value = 0;
       Queuenode<T> *temp = this->first;
      if(this->first == NULL && this->last == NULL)
      {
         cout<<"Queue is Empty\n";
         return -1;
      }
      Value= this->first->data;
      this->first = this->first->next;
      delete temp;
      this->iCount--;
      return Value;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>    
void   Queue<T>:: Display()
{
     Queuenode<T> *temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";

}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name :  DeleteLast
//  Input         :  Delete Data of node
//  Output        :  Nothing
//  Description   :  Used to Delete node at Last position
//  Author        :  Kunal Dhanraj Patil         
//  Date          :  16/01/2026
//
/////////////////////////////////////////////////////////////////////////////
template<class T>
int   Queue<T>:: Count()
{
   return this->iCount;
}



//////////////////////////////// End of Library //////////////////////////////////
int main()
{
    int iChoice = 1;

    while(iChoice != 0)
    {
        cout<<"\n============================================\n";
        cout<<"      DATA STRUCTURE APPLICATION MENU\n";
        cout<<"============================================\n";
        cout<<"1. Singly Linear Linked List\n";
        cout<<"2. Doubly Linear Linked List\n";
        cout<<"3. Singly Circular Linked List\n";
        cout<<"4. Doubly Circular Linked List\n";
        cout<<"5. Stack\n";
        cout<<"6. Queue\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice: ";
        cin>>iChoice;

        switch(iChoice)
        {
        // ---------------- Singly Linear LL ----------------
        case 1:
        {
            SinglyLLL<int> *obj = new SinglyLLL<int>();
            int ch=1, val, pos;

            while(ch!=0)
            {
                cout<<"\n--- Singly Linear Linked List ---\n";
                cout<<"1 InsertFirst\n2 InsertLast\n3 InsertAtPos\n4 DeleteFirst\n5 DeleteLast\n6 DeleteAtPos\n7 Display\n8 Count\n0 Back\n";
                cin>>ch;

                switch(ch)
                {
                    case 1: cout<<"Enter value:"; cin>>val; obj->InsertFirst(val); break;
                    case 2: cout<<"Enter value:"; cin>>val; obj->InsertLast(val); break;
                    case 3: cout<<"Enter value & pos:"; cin>>val>>pos; obj->InsertAtPos(val,pos); break;
                    case 4: obj->DeleteFirst(); break;
                    case 5: obj->DeleteLast(); break;
                    case 6: cout<<"Enter pos:"; cin>>pos; obj->DeleteAtPos(pos); break;
                    case 7: obj->Display(); break;
                    case 8: cout<<"Count:"<<obj->Count()<<endl; break;
                }
            }
            delete obj;
            break;
        }

        // ---------------- Doubly Linear LL ----------------
        case 2:
        {
            DoublyLLL<char> *obj = new DoublyLLL<char>();
            int ch=1, pos;
            char val;

            while(ch!=0)
            {
                cout<<"\n--- Doubly Linear Linked List ---\n";
                cout<<"1 InsertFirst\n2 InsertLast\n3 InsertAtPos\n4 DeleteFirst\n5 DeleteLast\n6 DeleteAtPos\n7 Display\n8 Count\n0 Back\n";
                cin>>ch;

                switch(ch)
                {
                    case 1: cout<<"Enter char:"; cin>>val; obj->InsertFirst(val); break;
                    case 2: cout<<"Enter char:"; cin>>val; obj->InsertLast(val); break;
                    case 3: cout<<"Enter char & pos:"; cin>>val>>pos; obj->InsertAtPos(val,pos); break;
                    case 4: obj->DeleteFirst(); break;
                    case 5: obj->DeleteLast(); break;
                    case 6: cout<<"Enter pos:"; cin>>pos; obj->DeleteAtPos(pos); break;
                    case 7: obj->Display(); break;
                    case 8: cout<<"Count:"<<obj->Count()<<endl; break;
                }
            }
            delete obj;
            break;
        }

        // ---------------- Singly Circular LL ----------------
        case 3:
        {
            SinglyCLL<int> *obj = new SinglyCLL<int>();
            int ch=1, val, pos;

            while(ch!=0)
            {
                cout<<"\n--- Singly Circular Linked List ---\n";
                cout<<"1 InsertFirst\n2 InsertLast\n3 InsertAtPos\n4 DeleteFirst\n5 DeleteLast\n6 DeleteAtPos\n7 Display\n8 Count\n0 Back\n";
                cin>>ch;

                switch(ch)
                {
                    case 1: cout<<"Enter value:"; cin>>val; obj->InsertFirst(val); break;
                    case 2: cout<<"Enter value:"; cin>>val; obj->InsertLast(val); break;
                    case 3: cout<<"Enter value & pos:"; cin>>val>>pos; obj->InsertAtPos(val,pos); break;
                    case 4: obj->DeleteFirst(); break;
                    case 5: obj->DeleteLast(); break;
                    case 6: cout<<"Enter pos:"; cin>>pos; obj->DeleteAtPos(pos); break;
                    case 7: obj->Display(); break;
                    case 8: cout<<"Count:"<<obj->Count()<<endl; break;
                }
            }
            delete obj;
            break;
        }

        // ---------------- Doubly Circular LL ----------------
        case 4:
        {
            DoublyCLL<int> *obj = new DoublyCLL<int>();
            int ch=1, val, pos;

            while(ch!=0)
            {
                cout<<"\n--- Doubly Circular Linked List ---\n";
                cout<<"1 InsertFirst\n2 InsertLast\n3 InsertAtPos\n4 DeleteFirst\n5 DeleteLast\n6 DeleteAtPos\n7 Display\n8 Count\n0 Back\n";
                cin>>ch;

                switch(ch)
                {
                    case 1: cout<<"Enter value:"; cin>>val; obj->InsertFirst(val); break;
                    case 2: cout<<"Enter value:"; cin>>val; obj->InsertLast(val); break;
                    case 3: cout<<"Enter value & pos:"; cin>>val>>pos; obj->InsertAtPos(val,pos); break;
                    case 4: obj->DeleteFirst(); break;
                    case 5: obj->DeleteLast(); break;
                    case 6: cout<<"Enter pos:"; cin>>pos; obj->DeleteAtPos(pos); break;
                    case 7: obj->Display(); break;
                    case 8: cout<<"Count:"<<obj->Count()<<endl; break;
                }
            }
            delete obj;
            break;
        }

        // ---------------- Stack ----------------
        case 5:
        {
            Stack<char> *sobj = new Stack<char>();
            int ch=1;
            char val;

            while(ch!=0)
            {
                cout<<"\n--- Stack ---\n";
                cout<<"1 Push\n2 Pop\n3 Peep\n4 Display\n5 Count\n0 Back\n";
                cin>>ch;

                switch(ch)
                {
                    case 1: cout<<"Enter char:"; cin>>val; sobj->push(val); break;
                    case 2: cout<<"Popped:"<<sobj->pop()<<endl; break;
                    case 3: cout<<"Top:"<<sobj->peep()<<endl; break;
                    case 4: sobj->Display(); break;
                    case 5: cout<<"Count:"<<sobj->Count()<<endl; break;
                }
            }
            delete sobj;
            break;
        }

        // ---------------- Queue ----------------
        case 6:
        {
            Queue<double> *qobj = new Queue<double>();
            int ch=1;
            double val;

            while(ch!=0)
            {
                cout<<"\n--- Queue ---\n";
                cout<<"1 Enqueue\n2 Dequeue\n3 Display\n4 Count\n0 Back\n";
                cin>>ch;

                switch(ch)
                {
                    case 1: cout<<"Enter value:"; cin>>val; qobj->enqueue(val); break;
                    case 2: cout<<"Removed:"<<qobj->dequeue()<<endl; break;
                    case 3: qobj->Display(); break;
                    case 4: cout<<"Count:"<<qobj->Count()<<endl; break;
                }
            }
            delete qobj;
            break;
        }

        case 0:
            cout<<"Thank you for using Data Structure Application\n";
            break;

        default:
            cout<<"Invalid choice\n";
        }
    }

    return 0;
}