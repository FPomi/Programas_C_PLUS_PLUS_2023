#include <iostream>
#include <string>
#include <list>

using namespace std;
//using uint = unsigned int;

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// Pre: 0 <= mes < 12
unsigned int dias_en_mes(unsigned int mes) {
    unsigned int dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
	// Completar declaraciones funciones
    Fecha (int mes, int dia);
    int mes();
    int dia();
    
	//#if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    //#endif

    void incrementar_dia();
	
  private:
	int _mes;
	int _dia;
	string _fecha;
	
};

Fecha::Fecha(int mes, int dia): _mes(mes), _dia(dia){}

int Fecha::mes(){
	return _mes;
}

int Fecha::dia(){
	return _dia;
}

ostream& operator<<(ostream& os,  Fecha f) {
	os << f.dia() << "/" << f.mes();
	return os;
}

//#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();
    return (igual_dia && igual_mes);
}
//#endif

void Fecha::incrementar_dia(){
	
	if (this->dia() == dias_en_mes(this->mes())){
		this->_dia = 1;
		if (this->mes() == 12){
			this->_mes = 1;
		}else{
			this->_mes = mes() + 1;
		}
	}else{
		this->_dia = this->dia() + 1;
 	}
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// Ejercicio 11, 12

// Clase Horario
class Horario {
  public:
  	
    Horario (unsigned int hora, unsigned int min);
    unsigned int hora();
    unsigned int min();
    bool operator<(Horario o);
	
  private:
	unsigned int _hora;
	unsigned int _min;
	string _horario;
	
};

Horario::Horario(unsigned int hora, unsigned int min): _hora(hora), _min(min){}

unsigned int Horario::hora(){
	return _hora;
}

unsigned int Horario::min(){
	return _min;
}

ostream& operator<<(ostream& os, Horario h) {
	os << h.hora() << ":" << h.min();
	return os;
}

bool Horario::operator<(Horario o) {
    bool menor_min = this->min() < o.min();
    bool menor_hora = this->hora() < o.hora();
    return (menor_min || menor_hora);
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// Ejercicio 13

// Clase Recordatorio
class Recordatorio {
  public:
  	
    Recordatorio (Fecha f, Horario h, string r);
    Fecha fecha();
    Horario horario();
	string recordatorio();
	
  private:
	Fecha _fecha;
	Horario _horario;
	string _recordatorio;
	
};

Recordatorio::Recordatorio(Fecha f, Horario h, string r): _fecha(f), _horario(h), _recordatorio(r){}

Fecha Recordatorio::fecha(){
	return _fecha;
}

Horario Recordatorio::horario(){
	return _horario;
}

string Recordatorio::recordatorio(){
	return _recordatorio;
}

ostream& operator<<(ostream& os, Recordatorio r) {
	os << r.recordatorio() << " @ " << r.fecha() << " " << r.horario();
	return os;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// Ejercicio 14

// Clase Agenda
class Agenda {
	
	public:
		Agenda(Fecha fecha_inicial);
		void agregar_recordatorio(Recordatorio rec);
		void incrementar_dia();
		list <Recordatorio> recordatorios_de_hoy();
		Fecha hoy();
	
	private:
		Fecha _hoy;
		list<Recordatorio> _recordatorios_de_hoy;
		
};

Agenda::Agenda(Fecha fecha_inicial): _hoy(fecha_inicial){}

bool horarioMenorAMayor (Recordatorio r1, Recordatorio r2){
	return (r1.horario() < r2.horario());
}

void Agenda::agregar_recordatorio(Recordatorio rec){
	_recordatorios_de_hoy.push_back(rec);
	_recordatorios_de_hoy.sort(horarioMenorAMayor);
}

void Agenda::incrementar_dia(){
	_hoy.incrementar_dia();
}

list<Recordatorio> Agenda::recordatorios_de_hoy(){
	return _recordatorios_de_hoy;
}

Fecha Agenda::hoy(){
	return _hoy; 
}

ostream& operator<<(ostream& os, Agenda a) {

	list <Recordatorio> recordatorios_de_hoy = a.recordatorios_de_hoy();
	
	os << a.hoy() << endl << "=====" << endl;
	
	for (list<Recordatorio>::iterator it = recordatorios_de_hoy.begin(); it != recordatorios_de_hoy.end(); it = recordatorios_de_hoy.begin()){
		
		if (recordatorios_de_hoy.front().fecha() == a.hoy()){
			os << *it << endl;
		}
		
		recordatorios_de_hoy.pop_front();
		
	}	
	
	return os;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
