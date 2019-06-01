
class TMonom
{
protected:
	int n; //������
	double c; //�����������
	unsigned* power;//�������
	TMonom* next;//��������� �����
public:
	TMonom(int _n, unsigned* _p = 0, double _c = 0);
	TMonom(TMonom& monom);
	~TMonom();

    int GetN(); //������
	double GetC(); //�����������
	unsigned* GetPower();//�������
	TMonom* GetNext();//��������� �����

	void SetN(int _n); //������
	void SetC(double _c); //�����������
	void SetPower(unsigned* _power);//�������
	void SetNext(TMonom* _next);//��������� �����

	TMonom& operator = (TMonom& monom);
	TMonom operator + (TMonom& monom);
	TMonom operator - (TMonom& monom);
	TMonom operator * (TMonom& monom);
	
	bool operator > (TMonom& monom);
	bool operator < (TMonom& monom);
	bool operator == (TMonom& monom);
};

	TMonom::TMonom(int _n, unsigned* _p, double _c)
	{
		if(_n <= 0)
			throw(1);
		n = _n;
		c = _c;
		power = new unsigned int[n];
		if(_p != 0)
			for(int i = 0; i < n; i++)
				power[i] = _p[i];
		else
			for(int i = 0; i < n; i++)
				power[i] = 0;
		next = 0;
	}
	TMonom::TMonom(TMonom& monom)
	{
		n = monom.n;
		c = monom.c;
		next = monom.next;
		power = new unsigned int[n];
			for(int i = 0; i < n; i++)
				power[i] = monom.power[i];
	}
	TMonom::~TMonom()
	{
		delete[] power;
	}

    int TMonom::GetN()
	{
		return n;
	}
	double TMonom::GetC()
	{
		return c;
	}
	unsigned* TMonom::GetPower()
	{
		return power;
	}
	TMonom* TMonom::GetNext()
	{
		return next;
	}

	void TMonom::SetN(int _n)
	{
		if (_n <= 0)
			throw (1);
		unsigned* tmp = new unsigned int[n];
		for (int i = 0; i < n; i++)
			tmp[i] = power[i];
		delete[] power;
		power = new unsigned int[_n];
		// �������� ������� �� n � _n:
		for (int i = 0; i < (n > _n ? _n : n); i++)
			power[i] = tmp[i];
		delete[] tmp;
	}
	void TMonom::SetC(double _c)
	{
		c = _c;
	}
	void TMonom::SetPower(unsigned* _power)
	{
		try
		{
			for(int i = 0; i < n; i++)
				if (_power[i] >= 0)
					power[i] = _power[i];
				else
					throw 1;
		}
		catch(int ex)
		{
			throw ex;
		}
		catch(...)
		{
			throw 2;
		}
	}
	void TMonom::SetNext(TMonom* _next)
	{
		next = _next;
	}

	TMonom& TMonom::operator = (TMonom& monom)
	{
		if(this != &monom)
		{
			if (n != monom.n)
			{
				delete[] power;
				power = new unsigned int[n];
			}
			n = monom.n;
			c = monom.c;
			next = monom.next;		
			for(int i = 0; i < n; i++)
				power[i] = monom.power[i];
		}
		return *this;
	}
	TMonom TMonom::operator + (TMonom& monom)
	{
		if(n != monom.n)
			throw 1;
		TMonom tmp(monom);
		if(*this == monom)
			tmp.c = c + monom.c;
		else 
			throw 1;
		return tmp;
	}
	TMonom TMonom::operator - (TMonom& monom)
	{
		if(n != monom.n)
			throw 1;
		TMonom tmp(monom);
		if(*this == monom)
			tmp.c = c - monom.c;
		else 
			throw 1;
		return tmp;
	}
	TMonom TMonom::operator * (TMonom& monom)
	{
		if(n != monom.n)
			throw 1;
		TMonom tmp(monom);
			tmp.c = c * monom.c;
		for (int i = 0; i < n; i++)
			tmp.power[i] = power[i] + monom.power[i];
		return tmp;
	}
	
	bool TMonom::operator > (TMonom& monom)
	{
	};
	bool TMonom::operator < (TMonom& monom)
	{
	};
	bool TMonom::operator == (TMonom& monom)
	{
	};