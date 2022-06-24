#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

class Manufacturer {
public:

	Manufacturer() {
		guarantee = 0;
		name = new char[10];
		adress = new char[10];
		phone_number = new char[10];
		strcpy_s(name, 10, "Empty");
		strcpy_s(adress, 10, "Empty");
		strcpy_s(phone_number, 10, "Empty");
	}

	Manufacturer(int guaranteE, char* namE, char* adresS, char* phone_numbeR) {
		guarantee = guaranteE;
		name = new char[strlen(namE) + 1];
		adress = new char[strlen(adresS) + 1];
		phone_number = new char[strlen(phone_numbeR) + 1];
		strcpy_s(name, (strlen(namE) + 1), namE);
		strcpy_s(adress, strlen(adresS) + 1, adresS);
		strcpy_s(phone_number, strlen(phone_numbeR) + 1, phone_numbeR);
	}

	Manufacturer(const Manufacturer& other) {
		guarantee = other.guarantee;
		name = new char[strlen(other.name) + 1];
		adress = new char[strlen(other.adress) + 1];
		phone_number = new char[strlen(other.phone_number) + 1];
		strcpy_s(name, strlen(other.name) + 1, other.name);
		strcpy_s(adress, strlen(other.adress) + 1, other.adress);
		strcpy_s(phone_number, strlen(other.phone_number) + 1, other.phone_number);
	}


	int GetGuarantee() {
		return guarantee;
	}
	char* GetName() {
		return name;
	}
	char* GetAdress() {
		return adress;
	}
	char* GetPhone_Number() {
		return phone_number;
	}


	Manufacturer& SetGuarantee(int Guarantee) {
		guarantee = Guarantee;
		return *this;
	}
	Manufacturer& SetName(char* namE) {
		if (name) {
			delete[] name;
		}
		name = new char[strlen(namE) + 1];
		strcpy_s(name, strlen(namE) + 1, namE);
		return *this;
	}
	Manufacturer& SetAdress(char* adresS) {
		if (adress) {
			delete[] adress;
		}
		adress = new char[strlen(adresS) + 1];
		strcpy_s(adress, strlen(adresS) + 1, adresS);
		return *this;
	}
	Manufacturer& SetPhone_Number(char* phone_numbeR) {
		if (phone_number) {
			delete[] phone_number;
		}
		phone_number = new char[strlen(phone_numbeR) + 1];
		strcpy_s(phone_number, strlen(phone_numbeR) + 1, phone_numbeR);
		return *this;
	}

	void Print_Manufacturer() {
		cout << "Name of manufacturer: " << name << endl;
		cout << "Adress: " << adress << endl;
		cout << "Phone number: " << phone_number << endl;
		cout << "Guarantee period: " << guarantee << endl;
	}

	void ShortPrint() {
		cout << "\nName of manufacturer: " << name << endl;
	}

	bool operator == (const Manufacturer& other) {
		return (strcmp(name, other.name) == 0 &&
			strcmp(adress, other.adress) == 0 &&
			strcmp(phone_number, other.phone_number) == 0 &&
			guarantee == other.guarantee);
	}

	friend ostream& operator<<(ostream& out, Manufacturer& outstream);
	friend istream& operator>>(istream& in, Manufacturer& instream);


public:
	char* name;
	char* adress;
	char* phone_number;
	int guarantee;
};

istream& operator>>(istream& in, Manufacturer& instream) {
	cout << "Name of manufacturer: ";
	in.getline(instream.name, 20);
	cout << "Adress: ";
	in.getline(instream.adress, 20);
	cout << "Phone number : ";
	in.getline(instream.phone_number, 20);
	cout << "Guarantee period: ";
	in >> instream.guarantee;
	in.ignore(1, '\n');
	return in;
}
ostream& operator<<(ostream& out, Manufacturer& outstream) {
	out << "Name of manufacturer: " << outstream.name << endl;
	out << "Adress: " << outstream.adress << endl;
	out << "Phone number: " << outstream.phone_number << endl;
	out << "Guarantee: " << outstream.guarantee << endl;
	return out;
}

class Product {
public:
	Product() {
		price = 0;
		name_prod = new char[10];
		strcpy_s(name_prod, 10, "Empty");
	}

	Product(char* namE_prod, double pricE, int guaranteE, char* namE, char* adresS, char* phone_numbeR) :
		firm(guaranteE, namE, adresS, phone_numbeR) {
		price = pricE;
		name_prod = new char[strlen(namE_prod) + 1];
		strcpy_s(name_prod, (strlen(namE_prod) + 1), namE_prod);
	}

	Product(Product& other) :firm(other.firm) {
		price = other.price;
		name_prod = new char[strlen(other.name_prod) + 1];
		strcpy_s(name_prod, strlen(other.name_prod) + 1, other.name_prod);
	}

	~Product() {
		if (name_prod) {
			delete[] name_prod;
		}
	}

	double GetPrice() {
		return price;
	}
	char* GetName_prod() {
		return name_prod;
	}
	double GetGuarantee() {
		return firm.GetGuarantee();
	}
	char* GetName() {
		return firm.GetName();
	}
	char* GetAdress() {
		return firm.GetAdress();
	}
	char* GetPhone_Number() {
		return firm.GetPhone_Number();
	}

	Product& SetPrice(double pricE) {
		price = pricE;
		return *this;
	}
	Product& SetName_Prod(char* name_proD) {
		if (name_prod) {
			delete[] name_prod;
		}
		name_prod = new char[strlen(name_proD) + 1];
		strcpy_s(name_prod, strlen(name_proD) + 1, name_proD);
		return *this;
	}
	Product& SetFirm(int guaranteE, char* namE, char* adresS, char* phone_numbeR) {
		firm.SetGuarantee(guaranteE);
		firm.SetAdress(adresS);
		firm.SetName(namE);
		firm.SetPhone_Number(phone_numbeR);
		return *this;
	}

	virtual void Print() {
		cout << "Name of product: " << name_prod << endl;
		cout << fixed;
		cout << "Price of product: " << setprecision(2) << price << endl;
		firm.Print_Manufacturer();
	}

	void ShortPrint() {
		cout << "\nName of product: " << name_prod << " by " << firm.GetName() << endl;
	}

	bool operator == (Product& other) {
		return (strcmp(name_prod, other.name_prod) == 0 &&
			strcmp(firm.GetName(), other.firm.GetName()) == 0 &&
			strcmp(firm.GetAdress(), other.firm.GetAdress()) == 0 &&
			strcmp(firm.GetPhone_Number(), other.firm.GetPhone_Number()) == 0 &&
			price == other.price &&
			firm.GetGuarantee() == other.firm.GetGuarantee());
	}


	Product& SetWarehouse() {

		this->name_prod = new char[10];
		strcpy_s(name_prod, 10, "Unknown");
		this->price = 0;

		firm.name = new char[10];
		firm.adress = new char[10];
		firm.phone_number = new char[10];
		strcpy_s(firm.name, 10, "Unknown");
		strcpy_s(firm.adress, 10, "Unknown");
		strcpy_s(firm.phone_number, 10, "Unknown");
		firm.guarantee = 0;

		return *this;
	}

	friend ostream& operator<<(ostream& out, Product& outstream);
	friend istream& operator>>(istream& in, Product& instream);



public:
	char* name_prod;
	double price;
	Manufacturer firm;
};

istream& operator>>(istream& in, Product& instream) {
	in >> instream.firm;
	cout << "Name of product: ";
	in.getline(instream.name_prod, 20);
	cout << "Price: ";
	in >> instream.price;
	in.ignore(1, '\n');
	return in;
}
ostream& operator<<(ostream& out, Product& outstream) {
	out << endl << "Name of product: " << outstream.name_prod << endl;
	out << "Price of product: " << outstream.price << endl;
	out << outstream.firm;
	return out;
}

class Done_Product : public Product {
public:
	Done_Product() {
		quantity = 1;
		day = 11;
		month = 11;
		year = 1111;
	}

	Done_Product(int quantity, int year, int month, int day, char* namE_prod, double pricE, int guaranteE,
		char* namE, char* adresS, char* phone_numbeR) :quantity(quantity), year(year), month(month), day(day),
		Product(namE_prod, pricE, guaranteE, namE, adresS, phone_numbeR) {
	}

	Done_Product(Done_Product& other) :Product(other) {

		quantity = other.quantity;
		day = other.day;
		month = other.month;
		year = other.year;
	}

	~Done_Product() {

	}

	long GetQuantity() {
		return quantity;
	}
	int GetYear() {
		return year;
	}
	int GetMonth() {
		return month;
	}
	int GetDay() {
		return day;
	}
	Done_Product& SetQuantity(long quantitY) {
		quantity = quantitY;
		return *this;
	}
	Done_Product& SetYear(long yeaR) {
		year = yeaR;
		return *this;
	}
	Done_Product& SetMonth(long montH) {
		month = montH;
		return *this;
	}
	Done_Product& SetDay(long daY) {
		day = daY;
		return *this;
	}

	void Print() {
		cout << "Name of product: " << name_prod << endl;
		cout << fixed;
		cout << "Price of product: " << setprecision(2) << price << endl;
		cout << quantity << " products was done " << day << " " << month << " " << year << endl;
	}

	void Short_Print_Done_Product() {
		cout << quantity << " products was done " << day << " " << month << " " << year << endl;
	}

	Done_Product& operator ++() {
		quantity++;
		return *this;
	}

	Done_Product& operator +=(Done_Product& other) {
		quantity += other.quantity;
		return *this;
	}

	bool operator < (const Done_Product& other) {
		return (quantity < other.quantity);
	}

	Done_Product(Product& other);
	friend Product;

protected:
	int quantity;
	int year, month, day;
};

class Sold_Product : public Done_Product {
public:
	Sold_Product() {
		number = ++count;
		quantity_sold = 2;
		day_sold = 2;
		month_sold = 22;
		year_sold = 2222;
	}

	Sold_Product(int year_sold, int month_sold, int day_sold, long quantity_sold,
		long quantity, int year, int month, int day, char* namE_prod, double pricE, int guaranteE,
		char* namE, char* adresS, char* phone_numbeR) :year_sold(year_sold), month_sold(month_sold),
		day_sold(day_sold), quantity_sold(quantity_sold), Done_Product(quantity, year, month, day,
			namE_prod, pricE, guaranteE, namE, adresS, phone_numbeR) {
		number = ++count;
	}

	Sold_Product(Sold_Product& other) :Done_Product(other) {
		number = ++count;
		quantity_sold = other.quantity_sold;
		day_sold = other.day_sold;
		month_sold = other.month_sold;
		year_sold = other.year_sold;

	}

	~Sold_Product() {
		number = count--;
	}

	long GetQuantity_Sold() {
		return quantity_sold;
	}
	int GetYear_Sold() {
		return year_sold;
	}
	int GetMonth_Sold() {
		return month_sold;
	}
	int GetDay_Sold() {
		return day_sold;
	}

	Sold_Product& SetQuantity_Sold(long quantitY) {
		quantity_sold = quantitY;
		return *this;
	}
	Sold_Product& SetYear_Sold(long yeaR) {
		year_sold = yeaR;
		return *this;
	}
	Sold_Product& SetMonth_Sold(long montH) {
		month_sold = montH;
		return *this;
	}
	Sold_Product& SetDay_Sold(long daY) {
		day_sold = daY;
		return *this;
	}

	void Print_Sold_Product() {
		cout << quantity << " products was done " << day << " " << month << " " << year << endl;
		cout << "Product number: " << number << " - " << quantity_sold << " products was sold " << day_sold << " " << month_sold << " " << year_sold << endl;
	}
private:
	int year_sold, month_sold, day_sold;
	long quantity_sold;
	static int count;
	int number;
};

int Sold_Product::count = 0;

class Warehouse {
public:
	Warehouse() {
		this->array_size = 2;
		array = new Product[array_size];

		this->number = 1;
	}

	Warehouse(int n) {
		this->array_size = n;
		array = new Product[array_size];
		for (int i = 0; i < this->array_size; i++) {
			array[i].SetWarehouse();
		}
		this->number = 1;
	}

	Warehouse(const Warehouse& other) {
		this->number = other.number;
		this->array_size = other.array_size;
		for (int i = 0; i < this->array_size; i++) {
			array[i] = other.array[i];
		}
	}


	~Warehouse() {
		delete[] array;
	}

	Product& operator[] (int val) {
		if ((val < array_size) && (val >= 0)) {
			return this->array[val];
		}
		else {
			cout << "Impossible" << endl;
		}
	}

	int  GetNumber() {
		return number;
	}

	void PrintNumber() {
		cout << "number:" << number << endl;
	}

private:
	int number;
	int array_size;
	Product* array;
};

Done_Product::Done_Product(Product& other) {
	this->price = other.price;
	this->firm = other.firm;
	this->name_prod = new char[strlen(other.name_prod) + 1];
	strcpy_s(this->name_prod, strlen(other.name_prod) + 1, other.name_prod);
	quantity = 100000;
	year = 1000;
	month = 10;
	day = 10;
}

template<class T>
void overlap(T arr1[], T arr2[], int N) {
	T* q1 = arr1;
	T* q2 = arr2;
	int res = 0;
	int n = N;
	while (q1 && q2 && n) {
		if (*q1++ == *q2++) {
			res += 1;
		}
		n--;
	}
	if (res != N) {
		cout << "no" << endl;
	}
	else {
		cout << "yes" << endl;
	}
}

template<class T>
void print(T arr1[], T arr2[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr1[i] << "  ";
	}
	cout << endl << "----------------------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr2[i] << "  ";
	}
	cout << endl;
}



int main() {
	int N;
	char nam[]{ "Chiken" };
	char bir[]{ "Birds" };
	char cc[]{ "ccc" };
	char phon1[]{ "18-53-20" };

	char aa[]{ "aaa" };
	char bb[]{ "bb" };
	char ccc[]{ "cccc" };
	char phon2[]{ "12-52-23" };

	char bread[]{ "Bread" };
	char chleb[]{ "Chleb" };
	char aab[]{ "AAA b" };
	char phon3[]{ "64-45-12" };

	Product b(nam, 130.55, 1, bir, cc, phon1);
	Product e(nam, 130.55, 1, bir, cc, phon1);
	Done_Product c(20000, 2020, 10, 12, aa, 52.13, 12, bb, ccc, phon2);
	Sold_Product d(2020, 5, 28, 10000, 15000, 2020, 5, 25, bread, 50.12, 3, chleb, aab, phon3);

	Product arrr1[4] = { b, c, d, e };;
	Product arrr2[4] = { b, c, d, c };;

	int arr1[5] = { 1, 3, 3, 4, 6 };
	int arr2[5] = { 1, 3, 2, 4, 3 };

	char a1[7] = { "abcdes" };
	char a2[7] = { "abcdrs" };

	cout << "enter N: ";
	cin >> N;

	print(arrr1, arrr2, 4);
	cout << "For class: ";
	overlap(arrr1, arrr2, N);

	cout << "\n\n";
	print(arr1, arr2, 5);
	cout << "For array: ";
	overlap(arr1, arr2, N);

	cout << endl;
	print(a1, a2, 7);
	cout << "For char array: ";
	overlap(a1, a2, N);



	return 0;
}
