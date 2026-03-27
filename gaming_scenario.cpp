#include<iostream>
#include<string>


using namespace std;



class Character 
{
	protected:
	    int health_points;
	    double power_level;
	    int experience_points;
	    string name;
	    string type;

	public:
	    Character(int health_points, double power_level, int experience_points, string name, string type) 
	    {
	        this->health_points = health_points;
	        this->power_level = power_level;
	        this->experience_points = experience_points;
	        this->name = name;
	        this->type = type;
	    }
	
	    virtual void info() 
		{
	        cout<<endl;
	        cout<<"Character Name: "<< name << endl;
	        cout<<"Character Type: "<< type << endl;
	        cout<<"Health Points: "<< health_points << endl;
	        cout<<"Power Level: "<<power_level << endl;
	        cout<<"Experience: "<<experience_points << endl;
	    }
	
	    void welcomeMessage() 
		{
	        cout << "\n*** Welcome to the IMSciences Battle Arena! ***" << endl;
	    }
	
	    virtual void defense() = 0;
	    virtual void attack() = 0;
	    virtual double getAttackValue() = 0;
};

class Warrior : public Character
{
private:
    string weapon_name;
    double armor_strength;
    double range_level;

public:
    Warrior(string name, string type, int health_points, double power_level, int experience_points, 
            string weapon_name, double armor_strength, double range_level) 
        : Character(health_points, power_level, experience_points, name, type) 
    {
        this->weapon_name = weapon_name;
        this->armor_strength = armor_strength;
        this->range_level = range_level;
    }

    void info()  
    {
        cout << "~~~~~~~~~~Warrior~~~~~~~~~~~~~" << endl;
        Character::info();
        cout << "Weapon: " << weapon_name << endl;
        cout << "Armor Strength: " << armor_strength << endl;
        cout << "Rage Level: " << range_level << endl;
    }
    
    double getAttackValue() 
	{
		 return power_level + (range_level * 0.5);
	}

    void attack() 
	{
        cout << name << " attacks with " << weapon_name << "! Damage: " << getAttackValue() << endl;
    }

    void defense() 
	{
        cout << name << " defends with armor! Protection: " << (armor_strength * 0.8) << endl;
    }
};

class mage : public Character
{
private:
    string spell_name;
    double mana_points;
    double magic_multiplier;

public:
    mage(string name, string type, int health_points, double power_level, int experience_points, string spell_name,
         double mana_points, double magic_multiplier) : Character(health_points, power_level, experience_points, name, type)
    {
        this->spell_name = spell_name;
        this->mana_points = mana_points;
        this->magic_multiplier = magic_multiplier;
    }

    void info()
    {
        cout << "~~~~~~~~~~Magician~~~~~~~~~~~~~" << endl;
        Character::info();
        cout << "Spell Name : " << spell_name << endl;
        cout << "Mana Point : " << mana_points << endl;
        cout << "Magic Multiplier : " << magic_multiplier << endl;
    }
    
    
    double getAttackValue()
	{
		return power_level * magic_multiplier;
	}

    void attack()
	 {
        cout<<name<<" casts "<<spell_name << "! Magic Damage: " << getAttackValue()<< endl;
    }

    void defense()
	{
        cout<<name<<" uses Mana Shield! Protection: "<< (mana_points * 0.4) << endl;
    }
};

class archer : public Character
{
private:
    string bow_type;
    int arrows_count;
    double accuracy_rate;

public:
    archer(string name, string type, int health_points, double power_level, int experience_points,  
           string bow_type, int arrows_count, double accuracy_rate) 
        : Character(health_points, power_level, experience_points, name, type)
    {
        this->bow_type = bow_type;
        this->arrows_count = arrows_count;
        this->accuracy_rate = accuracy_rate;
    }
    
    void info()
    {
        cout << "~~~~~~~~~~Archer~~~~~~~~~~~~~" << endl;
        Character::info();
        cout << "Bow Type : " << bow_type << endl;
        cout << "Number of Arrows : " << arrows_count << endl;
        cout << "Accuracy Rate : " << accuracy_rate << endl;
    }

    double getAttackValue()
	 {
	 	 return (power_level * 1.2) * (accuracy_rate / 100);
	  }

    void attack()
	{
        cout << name << " shoots"<< bow_type<<"! Ranged Damage> "<<getAttackValue()<<endl;
    }

    void defense()
	 {
        cout<<name<<" dodges with agility! Defense> "<<(accuracy_rate * 0.5)<<endl;
    }
};

int main()
{
    Warrior w1("Bilal", "Warrior", 100, 15.2, 18, "Sword", 80.8, 20.0);
    mage m1("Ahmad", "Magician", 80, 25.0, 60, "Magic Ball", 90.8, 2.5);
    archer a1("Hammad", "Archer", 80, 25.0, 45, "Silver Bow", 50, 120.4);
    
    w1.welcomeMessage();
    
    w1.info();
    w1.attack();
    w1.defense();

    m1.info();
    m1.attack();
    m1.defense();

    a1.info();  
    a1.attack();
    a1.defense();

    cout << "\n~~~~~~~~~~ Battle Summary ~~~~~~~" << endl;
    double warrior_attact = w1.getAttackValue();
    double mage_attact = m1.getAttackValue();
    double archer_attact = a1.getAttackValue();

    if (warrior_attact > mage_attact && warrior_attact > archer_attact)
	{ 
		cout<<"Highest Attacker: Warrior ("<<warrior_attact<<")"<<endl;
	}
    else if (mage_attact > warrior_attact && mage_attact > archer_attact)
	{	  
		cout<< "Highest Attacker: Magician ("<<mage_attact<<")"<<endl;
	}
    else 
	{
	cout<<"Highest Attacker: Archer ("<<archer_attact<<")"<<endl;
	}
    return 0;
}
