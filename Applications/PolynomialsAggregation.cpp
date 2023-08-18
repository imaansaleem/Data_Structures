#include<iostream>
#include<cmath>

using namespace std;

int exponentArray[10]={3, 2, 1, 0};
int coefficientArray[10]={1,2,3,4,5,6,7,8,9,10};

class Term{
	public:
	int exp;
	int coeff;
	
	public:
	Term(int coefficient, int exponent){  
		setexp(exponent);
		setcoeff(coefficient);
	}
	void setexp(int exponent){
		exp=exponent;
	}
	
	void setcoeff(float coefficient){
		coeff=coefficient;
	}
};

class Polynomial{
	Term *termArray[15]; //simple array will create objects of required side at once so non parameterized constructor will be called
	int terms; //array pointers will alow each pointer to create objects when required with the option of parameterized constructor calling
	
	void copy(const Polynomial &B, int start){
		for(;start<B.terms;terms++,start++){
			termArray[terms]->coeff=B.termArray[start]->coeff;
			termArray[terms]->exp=B.termArray[start]->exp;
		}
	}
	
	public:
	Polynomial(){
		for(int i=0;i<15;i++)
			termArray[i]=new Term(0,0);
			terms=0;
	}
	
	Polynomial(int terms){
		this->terms=terms;
		for(int i=0;i<terms;i++)
			termArray[i]=new Term(coefficientArray[i], exponentArray[i]);
	}
	
	Polynomial operator+(const Polynomial& B){
		Polynomial result;
		int i=0; //counter for 1st polynomial
		int j=0; //counter for 2nd polynomial
		B.termArray[0]->setexp(4); //try this if you want different exponents
		B.termArray[1]->setexp(2);
		result.terms=0;
		while(i<terms && j<B.terms){
			if(termArray[i]->exp==B.termArray[j]->exp){
				result.termArray[result.terms]->coeff=termArray[i]->coeff+B.termArray[j]->coeff;
				result.termArray[result.terms]->exp=termArray[i]->exp;
				result.terms++;
				i++;
				j++;
			}
			else if(termArray[i]->exp>B.termArray[j]->exp){
				result.termArray[result.terms]->coeff=termArray[i]->coeff; //if-else if for random exponents
				result.termArray[result.terms]->exp=termArray[i]->exp;
				result.terms++;
				i++;
			}
		
			else if(termArray[i]->exp<B.termArray[j]->exp){
				result.termArray[result.terms]->coeff=B.termArray[j]->coeff;
				result.termArray[result.terms]->exp=B.termArray[i]->exp;
				result.terms++;
				j++;
			}
		}
		
		if(terms>B.terms)
			result.copy(*this,i); //copying remaining terms ie larger termed polynomial
		else
			result.copy(B,j);
		return result;
	}
	
	Polynomial operator-(const Polynomial& B){
		Polynomial newPol=*this;
			for(int i=0;i<B.terms;i++)
				B.termArray[i]->coeff*=(-1);
			newPol=newPol+B;
		return newPol;
	}
	
	Polynomial operator*(const Polynomial& P){
		Polynomial result;
	//	P.termArray[0]->setexp(2); //try this if you want different exponents
	//	P.termArray[1]->setexp(4);
		int k=1,i, l;
		result.terms=0;
		for(i=0;i<terms;i++){
			for(int j=0;j<P.terms;j++){
				if(result.termArray[i+j]->coeff==0)
					result.terms++; //only increment when terms are different ie when addition is not performed addition is only not performed when coefficient at that position is zero
				result.termArray[i+j]->coeff+=termArray[i]->coeff*P.termArray[j]->coeff;
				result.termArray[i+j]->exp=termArray[i]->exp+P.termArray[j]->exp;
			}
		}
		return result;
	}
	
	
	friend ostream & operator<<(ostream& out, const Polynomial& X){
		for(int i=0;i<X.terms;i++){
			out << X.termArray[i]->coeff << "x^" << X.termArray[i]->exp;
			if(i<X.terms-1)
			cout  << "+" ;
		}
		out << '\n';
		return out;
	}
	
	int& operator()(int n){
		int sum=0;
		for(int i=0;i<terms;i++)
			sum=sum+pow(n,termArray[i]->exp)*termArray[i]->coeff;
		return sum;
	}
};

int main()
{
	Polynomial p1(4);
	Polynomial p2(2);
	Polynomial p3=p1+p2;
	cout << "Polynomial 1:" << endl;
	cout << p1 << endl;
	cout << "Polynomial 2:" << endl;
	cout << p2 << endl;
	cout << "Addition Of Polynomials: "<< endl;
	cout << p3 << endl;
	cout <<"Evaluation Of Polynomials: "<< endl;
	cout << p1(2) << endl << endl;
	cout <<"Subtraction Of Polynomials: "<< endl;
	Polynomial p4=p1-p2;
	cout << p4 << endl;
	Polynomial p11(3);
	Polynomial p22(2);
	cout <<"Multiplication Of Polynomials: "<< endl;
	Polynomial p5=p11*p22;
	cout << p5 << endl;
	return 0;
}
