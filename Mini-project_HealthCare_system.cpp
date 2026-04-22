#include <iostream>
#include <string>
using namespace std;

int patientCount     = 0;
int doctorCount      = 0;
int appointmentCount = 0;
int billCount        = 0;

int nextPatientNum = 1;
int nextDoctorNum  = 1;
int nextApptNum    = 1;
int nextBillNum    = 1;


// convert integers to string 
string intToStr(int n) {
    if (n == 0) return "0";
    bool negative = (n < 0);
    if (negative) n = -n;
    char buf[20];
    int i = 19;
    buf[i] = '\0';
    while (n > 0) {
        buf[--i] = '0' + (n % 10);
        n /= 10;
    }
    if (negative) buf[--i] = '-';
    return string(buf + i);
}

// making zeros padded ID 
string makeID(string prefix, int num) {
    string s = intToStr(num);
    if (num < 10)        s = "00" + s;
    else if (num < 100)  s = "0"  + s;
    return prefix + s;
}

//  print double with 2 decimal places
void printDouble(double val) {
    if (val < 0) { cout << '-'; val = -val; }
    long long intPart = (long long)val;
    long long fracPart = (long long)((val - intPart) * 100.0 + 0.5);
    if (fracPart >= 100) { intPart++; fracPart -= 100; }
    cout << intPart << '.';
    if (fracPart < 10) cout << '0';
    cout << fracPart;
}

void printPadded(const string& s, int width) {
    cout << s;
    int spaces = width - (int)s.size();
    for (int i = 0; i < spaces; i++) cout << ' ';
}

void printDoubleWidth(double val, int width) {

    if (val < 0) { val = -val; }
    long long intPart = (long long)val;
    long long fracPart = (long long)((val - intPart) * 100.0 + 0.5);
    if (fracPart >= 100) { intPart++; fracPart -= 100; }
    string frac = (fracPart < 10 ? "0" : "") + intToStr((int)fracPart);
    string numStr = intToStr((int)intPart) + "." + frac;
    int spaces = width - (int)numStr.size();
    for (int i = 0; i < spaces; i++) cout << ' ';
    cout << numStr;
}

class Person {
private:
    string name;
    int    age;
    string contact;
    string address;

public:
    Person() {
        name    = "Unknown";
        age     = 0;
        contact = "N/A";
        address = "N/A";
    }

    Person(string iname, int iage, string cont, string addr) {
        name    = iname;
        age     = iage;
        contact = cont;
        address = addr;
    }

    virtual ~Person() {}

    string getName()    { return name; }
    int    getAge()     { return age; }
    string getContact() { return contact; }
    string getAddress() { return address; }

    void setName(string n)    { name = n; }
    void setAge(int a)        { if (a > 0) age = a; }
    void setContact(string c) { contact = c; }
    void setAddress(string a) { address = a; }

    virtual void display() {
        cout << "  Name    : " << name    << "\n";
        cout << "  Age     : " << age     << "\n";
        cout << "  Contact : " << contact << "\n";
        cout << "  Address : " << address << "\n";
    }
};

class Doctor : public Person {
private:
    string doctorID;
    string specialisation;
    double fee;
    bool   available;

public:
    Doctor() : Person() {
        doctorID       = "D000";
        specialisation = "General";
        fee            = 0.0;
        available      = true;
    }

    Doctor(string name, int age, string contact, string address,
           string id, string spec, double f)
        : Person(name, age, contact, address) {
        doctorID       = id;
        specialisation = spec;
        fee            = f;
        available      = true;
    }

    ~Doctor() {}

    string getDoctorID()       { return doctorID; }
    string getSpecialisation() { return specialisation; }
    double getFee()            { return fee; }
    bool   isAvailable()       { return available; }

    void setDoctorID(string id)       { doctorID = id; }
    void setSpecialisation(string sp) { specialisation = sp; }
    void setFee(double f)             { if (f >= 0) fee = f; }
    void setAvailable(bool av)        { available = av; }

    void display() {
        cout << "+---------------------------------------+\n";
        cout << "  Doctor ID     : " << doctorID       << "\n";
        Person::display();
        cout << "  Specialisation: " << specialisation << "\n";
        cout << "  Fee           : PKR ";
        printDouble(fee);
        cout << "\n";
        cout << "  Available     : " << (available ? "Yes" : "No") << "\n";
        cout << "+---------------------------------------+\n";
    }

    void display(bool showReminder) {
        display();
        if (showReminder) {
            cout << "  ** Fee Reminder: PKR ";
            printDouble(fee);
            cout << " per visit **\n";
        }
    }
};

class Patient : public Person {
private:
    string  patientID;
    string  bloodGroup;
    string  medicalHistory;
    Doctor* assignedDoctor;
    int     appointmentCount;

public:
    Patient() : Person() {
        patientID        = "P000";
        bloodGroup       = "Unknown";
        medicalHistory   = "None";
        assignedDoctor   = NULL;
        appointmentCount = 0;
    }

    Patient(string name, int age, string contact, string address,
            string id, string blood, string history)
        : Person(name, age, contact, address) {
        patientID        = id;
        bloodGroup       = blood;
        medicalHistory   = history;
        assignedDoctor   = NULL;
        appointmentCount = 0;
    }

    ~Patient() {}

    string  getPatientID()        { return patientID; }
    string  getBloodGroup()       { return bloodGroup; }
    string  getMedicalHistory()   { return medicalHistory; }
    Doctor* getAssignedDoctor()   { return assignedDoctor; }
    int     getAppointmentCount() { return appointmentCount; }

    void setPatientID(string id)      { patientID = id; }
    void setBloodGroup(string bg)     { bloodGroup = bg; }
    void setMedicalHistory(string mh) { medicalHistory = mh; }
    void assignDoctor(Doctor* doc)    { assignedDoctor = doc; }
    void incrementAppointments()      { appointmentCount++; }

    bool operator==(Patient& other) {
        return patientID == other.patientID;
    }

    void display() {
        cout << "+---------------------------------------+\n";
        cout << "  Patient ID  : " << patientID       << "\n";
        Person::display();
        cout << "  Blood Group : " << bloodGroup       << "\n";
        cout << "  Medical Hx  : " << medicalHistory   << "\n";
        cout << "  Appointments: " << appointmentCount << "\n";
        if (assignedDoctor)
            cout << "  Doctor      : Dr. " << assignedDoctor->getName()
                 << " (" << assignedDoctor->getSpecialisation() << ")\n";
        else
            cout << "  Doctor      : Not Assigned\n";
        cout << "+---------------------------------------+\n";
    }

    void display(bool summaryOnly) {
        if (summaryOnly)
            cout << "  [" << patientID << "]  " << getName() << "  |  " << bloodGroup << "\n";
        else
            display();
    }
};

class Appointment {
private:
    string   appointmentID;
    Patient* patient;
    Doctor*  doctor;
    string   date;
    string   timeSlot;
    string   status;
    string   notes;

public:
    Appointment() {
        appointmentID = "A000";
        patient       = NULL;
        doctor        = NULL;
        date          = "N/A";
        timeSlot      = "N/A";
        status        = "Scheduled";
        notes         = "";
    }

    Appointment(string id, Patient* pat, Doctor* doc,
                string dt, string time, string note = "") {
        appointmentID = id;
        patient       = pat;
        doctor        = doc;
        date          = dt;
        timeSlot      = time;
        status        = "Scheduled";
        notes         = note;
        if (patient) patient->incrementAppointments();
    }

    ~Appointment() {}

    string   getAppointmentID() { return appointmentID; }
    Patient* getPatient()       { return patient; }
    Doctor*  getDoctor()        { return doctor; }
    string   getDate()          { return date; }
    string   getTimeSlot()      { return timeSlot; }
    string   getStatus()        { return status; }
    string   getNotes()         { return notes; }

    void setStatus(string s) { status = s; }
    void setNotes(string n)  { notes = n; }

    void display() {
        cout << "+---------------------------------------+\n";
        cout << "  Appt ID : " << appointmentID << "\n";
        cout << "  Patient : " << (patient ? patient->getName() : "N/A") << "\n";
        cout << "  Doctor  : " << (doctor  ? "Dr. " + doctor->getName() : "N/A") << "\n";
        cout << "  Date    : " << date     << "\n";
        cout << "  Time    : " << timeSlot << "\n";
        cout << "  Status  : " << status   << "\n";
        cout << "  Notes   : " << (notes.empty() ? "None" : notes) << "\n";
        cout << "+---------------------------------------+\n";
    }

    void display(bool markComplete) {
        if (markComplete) status = "Completed";
        display();
    }
};


class Bill {
private:
    string billID;
    string patientID;
    string patientName;
    double consultationFee;
    double medicationCost;
    double labTestCost;
    double roomCharges;
    double discount;
    bool   paid;

public:
    Bill() {
        billID          = "B000";
        patientID       = "P000";
        patientName     = "Unknown";
        consultationFee = 0;
        medicationCost  = 0;
        labTestCost     = 0;
        roomCharges     = 0;
        discount        = 0;
        paid            = false;
    }

    Bill(string bID, Patient& pat, double consult, double meds,
         double lab, double room, double disc = 0.0) {
        billID          = bID;
        patientID       = pat.getPatientID();
        patientName     = pat.getName();
        consultationFee = consult;
        medicationCost  = meds;
        labTestCost     = lab;
        roomCharges     = room;
        discount        = disc;
        paid            = false;
    }

    ~Bill() {}

    string getBillID()    { return billID; }
    string getPatientID() { return patientID; }
    bool   isPaid()       { return paid; }

    double getTotal() {
        return (consultationFee + medicationCost + labTestCost + roomCharges) - discount;
    }

    void setDiscount(double d) { if (d >= 0) discount = d; }
    void markAsPaid()          { paid = true; }

    Bill operator+(Bill& other) {
        Bill merged;
        merged.billID          = billID + "+" + other.billID;
        merged.patientID       = patientID;
        merged.patientName     = patientName;
        merged.consultationFee = consultationFee + other.consultationFee;
        merged.medicationCost  = medicationCost  + other.medicationCost;
        merged.labTestCost     = labTestCost     + other.labTestCost;
        merged.roomCharges     = roomCharges     + other.roomCharges;
        merged.discount        = discount        + other.discount;
        merged.paid            = paid && other.paid;
        return merged;
    }

    // print a bill row   
    void printRow(const string& label, double val) {
        cout << "| " << label << ": PKR ";
        printDoubleWidth(val, 12);
        cout << " |\n";
    }

    void display() {
        double subtotal = consultationFee + medicationCost + labTestCost + roomCharges;
        cout << "\n+======================================+\n";
        cout << "|         HOSPITAL INVOICE             |\n";
        cout << "+======================================+\n";
        cout << "| Bill ID  : "; printPadded(billID,      26); cout << "|\n";
        cout << "| Patient  : "; printPadded(patientName, 26); cout << "|\n";
        cout << "| Pt. ID   : "; printPadded(patientID,   26); cout << "|\n";
        cout << "+--------------------------------------+\n";
        printRow("Consultation Fee ", consultationFee);
        printRow("Medication Cost  ", medicationCost);
        printRow("Lab Tests        ", labTestCost);
        printRow("Room Charges     ", roomCharges);
        cout << "+--------------------------------------+\n";
        printRow("Subtotal         ", subtotal);
        printRow("Discount         ", discount);
        cout << "+--------------------------------------+\n";
        printRow("TOTAL DUE        ", getTotal());
        cout << "| Status           : ";
        printPadded((paid ? "PAID" : "UNPAID"), 18);
        cout << "|\n";
        cout << "+======================================+\n";
    }
};

const int MAX_PATIENTS     = 50;
const int MAX_DOCTORS      = 20;
const int MAX_APPOINTMENTS = 100;
const int MAX_BILLS        = 100;

Patient*     patients[MAX_PATIENTS];
Doctor*      doctors[MAX_DOCTORS];
Appointment* appointments[MAX_APPOINTMENTS];
Bill*        bills[MAX_BILLS];


void initArrays() {
    for (int i = 0; i < MAX_PATIENTS;     i++) patients[i]     = NULL;
    for (int i = 0; i < MAX_DOCTORS;      i++) doctors[i]      = NULL;
    for (int i = 0; i < MAX_APPOINTMENTS; i++) appointments[i] = NULL;
    for (int i = 0; i < MAX_BILLS;        i++) bills[i]        = NULL;
}

void freeAll() {
    for (int i = 0; i < patientCount;     i++) 
				delete patients[i];
				
    for (int i = 0; i < doctorCount;      i++) 
				delete doctors[i];
				
    for (int i = 0; i < appointmentCount; i++)
				delete appointments[i];
    
    for (int i = 0; i < billCount;        i++) 
				delete bills[i];
}

//Functions that do the works from the menu

void registerDoctor() {
    if (doctorCount >= MAX_DOCTORS) { cout << "Doctor list is full!\n"; return; }
    string name, contact, address, spec;
    int age; double fee;
    cout << "\n--- Register New Doctor ---\n";
    cout << "Enter Name---> "; cin.ignore(); getline(cin, name);
    cout << "Enter Age---> "; cin >> age;
    cout << "Enter Contact---> "; cin.ignore(); getline(cin, contact);
    cout << "Enter Address---> "; getline(cin, address);
    cout << "Enter Specialisation---> "; getline(cin, spec);
    cout << "Enter Fee (PKR)---> "; cin >> fee;
    string id = makeID("D", nextDoctorNum++);
    doctors[doctorCount++] = new Doctor(name, age, contact, address, id, spec, fee);
    cout << "\nDoctor registered successfully! ID: " << id << "\n";
}

void registerPatient() {
    if (patientCount >= MAX_PATIENTS) { cout << "Patient list is full!\n"; return; }
    string name, contact, address, blood, history;
    int age;
    cout << "\n--- Register New Patient ---\n";
    cout << "Enter Name---> "; 
	cin.ignore(); 
	getline(cin, name);
    cout << "Enter Age---> "; 
	cin >> age;
    cout << "Enter Contact---> "; 
	cin.ignore(); 
	getline(cin, contact);
    cout << "Enter Address---> "; 
	getline(cin, address);
    cout << "Enter Blood Grou---> "; 
	getline(cin, blood);
    cout << "Enter Medical History---> "; 
	getline(cin, history);
    string id = makeID("P", nextPatientNum++);
    patients[patientCount++] = new Patient(name, age, contact, address, id, blood, history);
    cout << "\nPatient registered successfully! ID: " << id << "\n";
}

void assignDoctor() {
    if (patientCount == 0 || doctorCount == 0) {
        cout << "No patients or doctors available.\n"; return;
    }
    cout << "\n--- Available Patients ---\n";
    for (int i = 0; i < patientCount; i++)
        cout << "  " << i+1 << ". [" << patients[i]->getPatientID() << "] " << patients[i]->getName() << "\n";
    cout << "Select Patient (number): "; int pc; cin >> pc;
    if (pc < 1 || pc > patientCount) { cout << "Invalid choice.\n"; return; }

    cout << "\n--- Available Doctors ---\n";
    for (int i = 0; i < doctorCount; i++)
        cout << "  " << i+1 << ". [" << doctors[i]->getDoctorID() << "] Dr. "
             << doctors[i]->getName() << " (" << doctors[i]->getSpecialisation() << ")\n";
    cout << "Select Doctor (number): "; int dc; cin >> dc;
    if (dc < 1 || dc > doctorCount) { cout << "Invalid choice.\n"; return; }

    patients[pc-1]->assignDoctor(doctors[dc-1]);
    cout << "\nDr. " << doctors[dc-1]->getName()
         << " assigned to " << patients[pc-1]->getName() << " successfully!\n";
}

void createAppointment() {
    if (patientCount == 0 || doctorCount == 0) {
        cout << "No patients or doctors available.\n"; return;
    }
    cout << "\n--- Available Patients ---\n";
    for (int i = 0; i < patientCount; i++)
        cout << "  " << i+1 << ". [" << patients[i]->getPatientID() << "] " << patients[i]->getName() << "\n";
    cout << "Select Patient (number): "; int pc; cin >> pc;
    if (pc < 1 || pc > patientCount) { cout << "Invalid choice.\n"; return; }

    cout << "\n--- Available Doctors ---\n";
    for (int i = 0; i < doctorCount; i++)
        cout << "  " << i+1 << ". [" << doctors[i]->getDoctorID() << "] Dr. " << doctors[i]->getName() << "\n";
    cout << "Select Doctor (number): "; int dc; cin >> dc;
    if (dc < 1 || dc > doctorCount) { cout << "Invalid choice.\n"; return; }

    string date, time, notes;
    cout << "Enter Date (YYYY-MM-DD) : "; cin.ignore(); getline(cin, date);
    cout << "Enter Time (e.g. 09:00 AM): "; getline(cin, time);
    cout << "Enter Notes (optional)   : "; getline(cin, notes);

    if (appointmentCount >= MAX_APPOINTMENTS) { cout << "Appointment list is full!\n"; return; }
    string id = makeID("A", nextApptNum++);
    appointments[appointmentCount++] = new Appointment(id, patients[pc-1], doctors[dc-1], date, time, notes);
    cout << "\nAppointment created successfully! ID: " << id << "\n";
}

void generateBill() {
    if (patientCount == 0) { cout << "No patients available.\n"; return; }
    cout << "\n--- Available Patients ---\n";
    for (int i = 0; i < patientCount; i++)
        cout << "  " << i+1 << ". [" << patients[i]->getPatientID() << "] " << patients[i]->getName() << "\n";
    cout << "Select Patient (number): "; int pc; cin >> pc;
    if (pc < 1 || pc > patientCount) { cout << "Invalid choice.\n"; return; }

    double consult, meds, lab, room, disc;
    cout << "\nEnter Consultation Fee : PKR "; cin >> consult;
    cout << "Enter Medication Cost  : PKR "; cin >> meds;
    cout << "Enter Lab Test Cost    : PKR "; cin >> lab;
    cout << "Enter Room Charges     : PKR "; cin >> room;
    cout << "Enter Discount         : PKR "; cin >> disc;

    if (billCount >= MAX_BILLS) { cout << "Bill list is full!\n"; return; }
    string id = makeID("B", nextBillNum++);
    bills[billCount++] = new Bill(id, *patients[pc-1], consult, meds, lab, room, disc);
    cout << "\nBill generated successfully! ID: " << id << "\n";
}

void viewPatientRecord() {
    if (patientCount == 0) { cout << "No patients registered.\n"; return; }
    cout << "\n--- Available Patients ---\n";
    for (int i = 0; i < patientCount; i++)
        cout << "  " << i+1 << ". [" << patients[i]->getPatientID() << "] " << patients[i]->getName() << "\n";
    cout << "Select Patient (number): "; int pc; cin >> pc;
    if (pc < 1 || pc > patientCount) { cout << "Invalid choice.\n"; return; }

    Patient* p = patients[pc-1];
    cout << "\n========================================\n";
    cout << "        COMPLETE PATIENT RECORD\n";
    cout << "========================================\n";
    p->display();

    cout << "\n--- Appointments ---\n";
    bool found = false;
    for (int i = 0; i < appointmentCount; i++) {
        if (appointments[i]->getPatient() == p) { appointments[i]->display(); found = true; }
    }
    if (!found) cout << "  No appointments found.\n";

    cout << "\n--- Bills ---\n";
    found = false;
    for (int i = 0; i < billCount; i++) {
        if (bills[i]->getPatientID() == p->getPatientID()) { bills[i]->display(); found = true; }
    }
    if (!found) cout << "  No bills found.\n";
}

void viewAllPatients() {
    if (patientCount == 0) { cout << "No patients registered yet.\n"; return; }
    cout << "\n--- All Registered Patients ---\n";
    for (int i = 0; i < patientCount; i++) patients[i]->display(true);
}

void viewAllDoctors() {
    if (doctorCount == 0) { cout << "No doctors registered yet.\n"; return; }
    cout << "\n--- All Registered Doctors ---\n";
    for (int i = 0; i < doctorCount; i++) doctors[i]->display();
}

void markBillPaid() {
    if (billCount == 0) { cout << "No bills available.\n"; return; }
    cout << "\n--- All Bills ---\n";
    for (int i = 0; i < billCount; i++) {
        cout << "  " << i+1 << ". [" << bills[i]->getBillID() << "]  Patient: "
             << bills[i]->getPatientID() << "  Total: PKR ";
        printDouble(bills[i]->getTotal());
        cout << "  Status: " << (bills[i]->isPaid() ? "PAID" : "UNPAID") << "\n";
    }
    cout << "Select Bill to mark as Paid (number): "; int bc; cin >> bc;
    if (bc < 1 || bc > billCount) { cout << "Invalid choice.\n"; return; }
    bills[bc-1]->markAsPaid();
    cout << "Bill " << bills[bc-1]->getBillID() << " marked as PAID.\n";
}

void mergeBills() {
    if (billCount < 2) { cout << "Need at least 2 bills to merge.\n"; return; }
    cout << "\n--- All Bills ---\n";
    for (int i = 0; i < billCount; i++) {
        cout << "  " << i+1 << ". [" << bills[i]->getBillID() << "]  "
             << bills[i]->getPatientID() << "  PKR ";
        printDouble(bills[i]->getTotal());
        cout << "\n";
    }
    cout << "Select First Bill  (number): "; int b1; cin >> b1;
    cout << "Select Second Bill (number): "; int b2; cin >> b2;
    if (b1 < 1 || b1 > billCount || b2 < 1 || b2 > billCount) {
        cout << "Invalid choice.\n"; return;
    }
    Bill merged = *bills[b1-1] + *bills[b2-1];
    cout << "\n--- Merged Invoice ---\n";
    merged.display();
}

void checkPatientEquality() {
    if (patientCount < 2) { cout << "Need at least 2 patients.\n"; return; }
    cout << "\n--- All Patients ---\n";
    for (int i = 0; i < patientCount; i++)
        cout << "  " << i+1 << ". [" << patients[i]->getPatientID() << "] " << patients[i]->getName() << "\n";
    cout << "Select First Patient  (number): "; int p1; cin >> p1;
    cout << "Select Second Patient (number): "; int p2; cin >> p2;
    if (p1 < 1 || p1 > patientCount || p2 < 1 || p2 > patientCount) {
        cout << "Invalid choice.\n"; return;
    }
    if (*patients[p1-1] == *patients[p2-1])
        cout << "\nResult: Same patient (IDs match).\n";
    else
        cout << "\nResult: Different patients (IDs do not match).\n";
}

void showMenu() {
    cout << "\n+======================================+\n";
    cout << "|      GENERAL HOSPITAL SYSTEM         |\n";
    cout << "+======================================+\n";
    cout << "|  1.  Register Doctor                 |\n";
    cout << "|  2.  Register Patient                |\n";
    cout << "|  3.  Assign Doctor to Patient        |\n";
    cout << "|  4.  Create Appointment              |\n";
    cout << "|  5.  Generate Bill                   |\n";
    cout << "|  6.  View Patient Record             |\n";
    cout << "|  7.  View All Patients               |\n";
    cout << "|  8.  View All Doctors                |\n";
    cout << "|  9.  Mark Bill as Paid               |\n";
    cout << "| 10.  Merge Two Bills                 |\n";
    cout << "| 11.  Check Patient Equality (==)     |\n";
    cout << "|  0.  Exit                            |\n";
    cout << "+======================================+\n";
    cout << "Enter your choice: ";
}

int main() {
    initArrays();
    cout << "=== Welcome to Kohat General Hospital System ===\n";
    int choice;
    do {
        showMenu();
        cin >> choice;
        if      (choice == 1)  registerDoctor();
        else if (choice == 2)  registerPatient();
        else if (choice == 3)  assignDoctor();
        else if (choice == 4)  createAppointment();
        else if (choice == 5)  generateBill();
        else if (choice == 6)  viewPatientRecord();
        else if (choice == 7)  viewAllPatients();
        else if (choice == 8)  viewAllDoctors();
        else if (choice == 9)  markBillPaid();
        else if (choice == 10) mergeBills();
        else if (choice == 11) checkPatientEquality();
        else if (choice == 0)  cout << "\nGoodbye! Exiting system...\n";
        else                   cout << "\nInvalid choice. Please try again.\n";
    } while (choice != 0);

    freeAll();
    return 0;
}
