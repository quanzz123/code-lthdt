#include<bits/stdc++.h>
using namespace std;

// Base class for IT devices
class ITDevice {
  protected:
    string name; // name of the device
    string code; // code of the device
    string date; // date of entry
    string status; // status of the device (in use or expired)
  public:
    // constructor
    ITDevice(string n, string c, string d, string s) {
      name = n;
      code = c;
      date = d;
      status = s;
    }
    // getter methods
    string getName() { return name; }
    string getCode() { return code; }
    string getDate() { return date; }
    string getStatus() { return status; }
    // setter methods
    void setName(string n) { name = n; }
    void setCode(string c) { code = c; }
    void setDate(string d) { date = d; }
    void setStatus(string s) { status = s; }
};

// Derived class for printers
class Printer : public ITDevice {
  protected:
    string color; // color of the printer
    int speed; // speed of printing
    int memory; // memory of the printer
  public:
    // constructor
    Printer(string n, string c, string d, string s, string col, int sp, int mem) : ITDevice(n, c, d, s) {
      color = col;
      speed = sp;
      memory = mem;
    }
    // getter methods
    string getColor() { return color; }
    int getSpeed() { return speed; }
    int getMemory() { return memory; }
    // setter methods
    void setColor(string col) { color = col; }
    void setSpeed(int sp) { speed = sp; }
    void setMemory(int mem) { memory = mem; }
};

// Derived class for black and white printers
class BWPrinter : public Printer {
  private:
    int resolution; // resolution of the printer in dpi (dots per inch)
  public:
    // constructor
    BWPrinter(string n, string c, string d, string s, string col, int sp, int mem, int res) : Printer(n, c, d, s, col, sp, mem) {
      resolution = res;
    }
    // getter method
    int getResolution() { return resolution; }
    // setter method
    void setResolution(int res) { resolution = res; }
};

// Derived class for color printers
class ColorPrinter : public BWPrinter {
  private:
    int colors; // number of colors supported by the printer
  public:
    // constructor
    ColorPrinter(string n, string c, string d, string s, string col, int sp, int mem, int res, int clrs) : BWPrinter(n, c, d, s, col, sp, mem,res) {
      colors = clrs;
    }
    // getter method
    int getColors() { return colors; }
    // setter method
    void setColors(int clrs) { colors = clrs; }
};

// Derived class for scanners
class Scanner : public ITDevice {
  private:
    int scanSpeed; // scanning speed in pages per minute (ppm)
  public:
  	// constructor
  	Scanner(string n, string c, string d, string s,int ss) : ITDevice(n,c,d,s) {
  		scanSpeed = ss;
  	}
  	// getter method
  	int getScanSpeed() { return scanSpeed; }
  	// setter method
  	void setScanSpeed(int ss) { scanSpeed = ss; }
};

// Derived class for projectors
class Projector : public ITDevice {
  private:
  	int maxHours; // maximum hours of projection 
  public:
  	// constructor 
  	Projector(string n,string c,string d,string s,int mh) : ITDevice(n,c,d,s){
  		maxHours = mh;
  	}
  	// getter method 
  	int getMaxHours() { return maxHours;}
  	// setter method 
  	void setMaxHours(int mh) { maxHours = mh;}
};
// A function to display information about an IT device 
void displayInfo(ITDevice* device){
	cout << "Name: " << device->getName() << endl;
	cout << "Code: " << device->getCode() << endl;
	cout << "Date: " << device->getDate() << endl;
	cout << "Status: " << device->getStatus() << endl;
	// check the type of the device using dynamic_cast
	Printer* printer = dynamic_cast<Printer*>(device);
	Scanner* scanner = dynamic_cast<Scanner*>(device);
	Projector* projector = dynamic_cast<Projector*>(device);
	if(printer != nullptr){
		// device is a printer
		cout << "Color: " << printer->getColor() << endl;
		cout << "Speed: " << printer->getSpeed() << endl;
		cout << "Memory: " << printer->getMemory() << endl;
		BWPrinter* bwprinter = dynamic_cast<BWPrinter*>(printer);
		ColorPrinter* colorprinter = dynamic_cast<ColorPrinter*>(printer);
		if(bwprinter != nullptr){
			// printer is a black and white printer
			cout << "Resolution: " << bwprinter->getResolution() << endl;
			if(colorprinter != nullptr){
				// printer is a color printer
				cout << "Colors: " << colorprinter->getColors() << endl;
			}
		}
	}
	else if(scanner != nullptr){
		// device is a scanner
		cout << "Scan Speed: " << scanner->getScanSpeed() << endl;
	}
	else if(projector != nullptr){
		// device is a projector
		cout << "Max Hours: " << projector->getMaxHours() << endl;
	}
}

// main function
int main(){
  // create some IT devices
  ITDevice* computer = new ITDevice("Computer", "C001", "01/01/2020", "In use");
  Printer* bwprinter = new BWPrinter("BW Printer", "P001", "01/02/2020", "In use", "Black", 20, 256, 600);
  Printer* colorprinter = new ColorPrinter("Color Printer", "P002", "01/03/2020", "Expired", "Color", 15, 512, 1200, 4);
  Scanner* scanner = new Scanner("Scanner", "S001", "01/04/2020", "In use", 30);
  Projector* projector = new Projector("Projector", "P003", "01/05/2020", "Expired", 1000);

  // display information about each device
  displayInfo(computer);
  cout << "\n";
  displayInfo(bwprinter);
  cout << "\n";
  displayInfo(colorprinter);
  cout << "\n";
  displayInfo(scanner);
  cout << "\n";
  displayInfo(projector);

  // delete the devices
  delete computer;
  delete bwprinter;
  delete colorprinter;
  delete scanner;
  delete projector;

  return 0;
}

