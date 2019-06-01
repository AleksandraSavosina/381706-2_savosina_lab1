#pragma once


#include <iostream>
#include <stack>

using namespace std;

class TTree
{
protected:
  TTree* nextLevel;   // �� ���� �������
  TTree* sameLevel;   // ������
  char d;				// �����, ������ �� ������ ������
  int level;			//�������, 0 - �����, 1 - ������
                      // 2 - �����, 3 - �����

  // ��� char d ������� ������ -1 

  //����������� ������ - ������, ��������� ����� ������
  // ������ ���������� ����������. ����������� � ������ TTree
  static int sizeMas;
  static char* mas;
  static TTree* start;	// ��������� �� ������ ����� ������
  static TTree* end;	// ��������� �� ����� ����� ������
  static TTree* _free;	// ��������� �� ������� ��������� ������


                          ///// 1 �����:
public:
  void Init(int size = 100); // ������������� ����� ������ ������� 100
  void GarbageCollector();	// ������ ������
  void* operator new (unsigned int size_t);
  void operator delete (void* d);
  // void* d - ����� ��������� �� �������������� �����, �� ���� ������ �����-�� ����� ������

public:
  TTree(int l)
  {
    level = l;
    nextLevel = NULL;
    sameLevel = NULL;
    d = 0;
  }

  TTree(char* st)	// ������
  {
    int l = strlen(st);
    level = 2;
    sameLevel = 0;
    nextLevel = new TTree(st[0]);
    TTree* symb = nextLevel;
    for (int i = 0; i < l; i++)
    {
      symb->sameLevel = new TTree(symb[i]);
      symb = symb->sameLevel;
    }
    d = 0;
  }

  TTree(char _d = 0)
  {
    d = _d;
    nextLevel = 0;
    sameLevel = 0;
    level = 3;
  }

  TTree(const TTree& a) // ��� ������, ������� ����� // �������
  {
    level = a.level;
    d = a.d;
    nextLevel = a.nextLevel;
    sameLevel = a.sameLevel;
  }

  ~TTree();

  TTree& operator=(const TTree& a)	// �����
  {
    if (level != a.level)
      throw "error";

    if (&a != this)
    {
      d = a.d;
      nextLevel = a.nextLevel;
      sameLevel = a.sameLevel;
    }

    return *this;
  }

  TTree& operator+=(const TTree& a)	// ������
  {
    // 
    TTree* copy = a.Clone();
    // ���� ������� ������������� ������ ��������� 
    // (� ������ ����� �����, � ����� ������ - ������)
    if (this->level < a.level)
      throw "error";

    TTree* i = this;
    while (i->level != copy->level)	// ����� �� ������, �� ������� ���� ���� �����
      i = i->nextLevel;

    while (i->sameLevel != 0) // ����� �� ���������� �������� ������
    {
      i = i->sameLevel;
      i->sameLevel = copy;
    }
  }

  TTree& operator+=(char c)
  {
    TTree symb(c);
    return (*this += symb);
  }

  TTree& operator+=(char* c)
  {
    TTree symb(c);
    return (*this += symb);
  }

  friend std::ostream operator<<(std::ostream& o, const TTree& a);

  char* ToStr()
  {
    stack <TTree*> t;
    t.push(this);
    int l = 0;	// length of word
    while (!t.empty())
    {
      TTree* i = t.pop(); // get
      if (i->level == 3)
        l++;
      if (i->sameLevel != 0)
        t.push(i->sameLevel);
      if (i->nextLevel != 0)
        t.push(i->nextLevel);
    }

    char *res = new char[l + 1];
    int j = 0;

    while (!t.empty())
    {
      TTree* i = t.top(); // get
      if (i->level == 3) // if it is a word
        l++;
      if (i->sameLevel != 0)
        t.push(i->sameLevel);
      if (i->nextLevel != 0)
        t.push(i->nextLevel);
    }
    res[l] = 0;
    return res;
  }

  void SetNextLevel(TTree* p);

  void SetSameLevel(TTree* p);

  void SetD(char _d) { d = _d; }
	
  void SetLevel(int _level) { level = _level; }
	
  TTree* GetNextLevel() { return nextLevel; }
	
	TTree* GetSameLevel(); { return sameLevel; }
	
	char GetD() { return d; }
	
    int GetLevel() { return level; }
	
	TTree* Clone()
	{
		TTree* resTree = new TTree(*this);
		// ���������� ������ 1 � ��� � �����
		stack<TTree*> st;
		stack<TTree*> copy;
		st.push(this);
		copy.push(resTree);
		while (!st.empty())
		{
			TTree* t1 = st.pop();	// get
			TTree* c1 = copy.pop();	// get
			if (t1->nextLevel != 0)
			{
				c1->nextLevel = new TTree(*t1->nextLevel);

			}
		}
			
	}
};

//void print(TTree* t = 0)
//{
//  if (t == 0)
//    t = this;

//  if (t->c != 0)
//  {
//    for (int i = 0; i < t->numC; i++)
//      print(t->c[i]);
//  }
//  std::cout << t->d << "\n";
//}

ostream operator<<(ostream& o, const TTree& a)
{
	stack<TTree*> stack;

	if (t == 0)
		t = this;

	stack.push(t);
	while (!stack.empty())
	{
		t = stack.top();
		stack.pop();

		if (t->sameLevel != 0)
			stack.push(t->sameLevel);
		if (t->nextLevel != 0)
			stack.push(t->nextLevel);
		if (t->level == 3)
			std::cout << t->d;
	}
	std::cout << "\n";
}



class Text	// level = 0, the highest
{
protected:
	TTree* root;
public:
	Text(char* s = 0)
	{
		root->SetNextLevel = new TTree(0); // 
		root->SetNextLevel(new TTree(1)); //������� ������ ������
		root->GetNextLevel()->SetNextLevel(new TTree(s)); //  ������ ��������� ������� �����, ������� ����� ������� s
	}

	Text(Text &t)
	{
		return this;
	}

    void Insert(int n, char* s);	// instr string after n
    

	
	void Insert(TTree* start, TTree* s��)	// instr s in start
    {
      TTree* tmp1 = str;
      TTree* tmp2 = root;
      TTreeIterator iter(root);

      while (tmp2 != start)
      {
        tmp2 = iter.GoNext();
      }
      tmp1->SetSameLevel(tmp2->GetSameLevel());
      tmp2->SetSameLevel(tmp1);
    }
	
	int Find(char* s);
	TTree Find(TTree* s);
	
	char* Copy(int start, int len); // ������� ������ ������� � ������-�� �����
	
    TTree Copy(TTree start, int len) // 
      TTree* res = new TTree(0);
    TTree* res_s = new TTree(1);
    TTree* res_w = new TTree(*start);
    res->SetNextLevel(res_s);
    res_s->SetNextLevel(res_w);

    TTreeIterator iter(root);
    int i = len;
    bool flag = false;
    while (iter.IsEnd() != true) 
    {
      TTree* tmp = iter.GoNext();
      if (tmp == start)
      {
        i--;
        flag = true;
      }
      else if (flag == true && tmp->GetLevel() == 3)
      {
        res_w->SetSameLevel(new TTree(*tmp));
        res_w = res_w->GetSameLevel();
        i--;
      }
      if (i == 0)
        break;
    }
    return res;
}
	
	void Delete(int start, int len);
	void Delete(TTree start, int len)
    {
      
      TTreeIterator iter(root);
      int i = len;
      bool flag = false;
      bool nextflag = false;
      bool sameflag = false;
      TTree* temp1;
      TTree* temp2;
      TTree* temp3;
      while (iter.IsEnd() != true)
      {
        TTree* tmp = iter.GoNext();
        if (tmp->GetSameLevel() == start)
        {
          temp1 = tmp;
          sameflag = true;
        }
        if (tmp->GetNextLevel() == start)
        {
          temp3 = tmp;
          nextflag = true;
        }
        if (tmp == start)
        {
          delete tmp;
          i--;
          flag = true;
        }
        else if (flag == true && tmp->GetLevel() == 3)
        {
          if (i == 1)
            temp2 = tmp->GetSameLevel();
          delete tmp;
          i--;
        }
        if (i == 0)
          break;
      
      }
      if (nextflag == true)
        temp3->SetNextLevel(temp2);
      if (sameflag == true)

    }

	
};



class TTreeIter // Iterator
{
protected:
	TTree* root;
	TTree* curr;
	stack<TTree*> st;
public:
	TTree& Iter(TTree* _root)	//
    {
      root = _root;
      curr = root;
      stack.Put(root);
    }
	TTree* GoNext()	// ���� �������� ����� while ������ � �������
    {
      TTree* tmp;
      if (stack.IsEmpty() == false)
        tmp = stack.Get();
      if (tmp->GetSameLevel() != NULL)
        stack.Put(tmp->GetSameLevel());
      if (tmp->GetNextLevel() != NULL)
        stack.Put(tmp->GetNextLevel());
      curr = tmp;
      return curr;
    }
	void Reset()	//
    {
      stack.Clear();
      stack.Put(root);
      curr = root;
    }
	bool End()		// ��� �� ������, ���� �� �������� ����. ��� ������ �� ������� - ��������� ���
    {
      if (stack.IsEmpty() == true)
        return true;
      else
        return false;
    }
    void PutInStack(TTree* tree)
    {
      stack.Put(tree);
    }
    TTree* operator () { return cur; }  // 
	TTreeIter & operator ++() // 
    {
      TTreeIterator tmp(root);
      return tmp;
    }
};