//Function For Displaying Linked List
void DisplayLinkedList(struct Node *Start)
{
  struct Node *Temp = NULL;
  Temp = Start;
  
  while(Temp != NULL)
    {
      printf("%d -> ", Temp->iData);
      Temp = (Temp->Next);
    }
  printf(" NULL\n");
}


//Function For Displaying Linked List in Reverse Order
void DisplayLinkedListReverse(struct Node *Start)
{
  struct Node *Temp = NULL;

  if(Start == NULL)
    {
      printf("NULL\n");
      return;
    }
  else
    {
      Temp = Start;
      while(Temp->Next != NULL)
	{
	  Temp = Temp->Next;
	}
      while(Temp != NULL)
	{
	  printf(" <- %d", Temp->iData);
	  Temp = Temp->Prev;
	}
    }

  printf("\n");
}


//Function For Counting Total Number of Elements in Linked List
int CountNodes(struct Node *Start)
{
  struct Node *Temp = NULL;
  int iCounter = 0;

  Temp = Start;
  while(Temp != NULL)
    {
      Temp = Temp->Next;
      iCounter++;
    }

  return iCounter;
}


//Function For Creating New Node
void CreateNewNode(int iValue, struct Node *NewNode)
{
  NewNode->iData = iValue;
  NewNode->Next = NULL;
  NewNode->Prev = NULL;
}


//Function For Inserting Element At First Position
void InsertAtFirst(int iValue, struct Node **Start)
{
  struct Node *NewNode = NULL;

  NewNode = (struct Node *)malloc(sizeof(struct Node));

  CreateNewNode(iValue, NewNode);

  if((*Start == NULL))
    {
      *Start = NewNode;
    }
  else
    {
      NewNode->Next = *Start;
      (*Start)->Prev = NewNode;
      *Start = NewNode;
    }
}


//Function For Inserting Element At Last Position
void InsertAtLast(int iValue, struct Node **Start)
{
  struct Node *NewNode = NULL, *Temp = NULL;
  
  NewNode = (struct Node *)malloc(sizeof(struct Node));

  CreateNewNode(iValue, NewNode);

  if((*Start == NULL))
    {
      *Start = NewNode;
    }
  else
    {
      Temp = (*Start);
      while((Temp->Next) != NULL)
	{
	  Temp = (Temp->Next);
	}
      
      (Temp->Next) = NewNode;
      (NewNode->Prev) = Temp;
    }
}


//Function For Insert Element At Given Position
void InsertAtPosition(int iPos, int iElement, struct Node **Start)
{
  struct Node *NewNode = NULL, *Temp = NULL;
  int iTotalNodes = 0, iCnt = 0;
  
  NewNode = (struct Node *)malloc(sizeof(struct Node));

  CreateNewNode(iElement, NewNode);

  iTotalNodes = CountNodes(*Start);

  if((iPos <= 0) || (iPos > (iTotalNodes + 1)))
    {
      printf("ERROR : ENTER VALID POSITION NUMBER...!!!\n");
    }
  else if(iPos == 1)
    {
      InsertAtFirst(iElement, Start);
    }
  else if(iPos == (iTotalNodes + 1))
    {
      InsertAtLast(iElement, Start);
    }
  else
    {
      Temp = *Start;
      while(iCnt != (iPos - 1))
	{
	  Temp = Temp->Next;
	  iCnt++;
	}
      NewNode->Next = Temp;
      NewNode->Prev = (Temp->Prev);
      (Temp->Prev)->Next = NewNode;
      Temp->Prev = NewNode;
    }
}


//Function For Delete The First Element of Linked List
void DeleteFirst(struct Node **Start)
{
  struct Node *Temp = NULL;
  
  if(*Start == NULL)
    {
      printf("\nERROR : LINKED LIST IS EMPTY\n");
    }
  else if(((*Start)->Next) == NULL)
    {
      free(*Start);
      *Start = NULL;
      }
  else
    {
      Temp = *Start;
      *Start = (*Start)->Next;
      free(Temp);
      (*Start)->Prev = NULL;
      Temp = NULL;
    }
}


//Function For Delete The Last Element of Linked List
void DeleteLast(struct Node **Start)
{
  struct Node *Temp = NULL;
  
  if(*Start == NULL)
    {
      printf("\nERROR : LINKED LIST IS EMPTY\n");
    }
  else if((*Start)->Next == NULL)
    {
      free(*Start);
      *Start = NULL;
    }
  else
    {
      Temp = *Start;
      while((Temp->Next)->Next != NULL)
	{
	  Temp = Temp->Next;
	}
      
      free(Temp->Next);
      Temp->Next = NULL;
    }
}


//Function For Delete The Element From Given Position of Linked List
void DeleteFromPosition(int iPos, struct Node **Start)
{
  struct Node *Temp = NULL;
  int iTotalNodes = 0, iCnt = 0;

  iTotalNodes = CountNodes(*Start);

  if(*Start == NULL)
    {
      printf("\nERROR : LINKED LIST IS EMPTY\n");
    }
  else if((iPos <= 0) || (iPos > iTotalNodes))
    {
      printf("\nERROR : ENTER VALID POSITION...!!!\n");
    }
  else if(iPos == 1)
    {
      DeleteFirst(Start);
    }
  else if(iPos == iTotalNodes)
    {
      DeleteLast(Start);
    }
  else
    {
      Temp = *Start;
      while(iCnt != (iPos - 1))
	{
	  iCnt++;
	  Temp = Temp->Next;
	}

      (Temp->Prev)->Next = Temp->Next;
      (Temp->Next)->Prev = Temp->Prev;
      free(Temp);
      Temp = NULL;
    }
}
