#define RESPONDENT 0
#define MANAGER 1
#define DIRECTOR 2

class Call{

};

class Employees{
public:
	Call * getnewcall();
	void escalate(Call *c);
private:
	int type;
	Call * a_call;
};

class CallHandler{
public:
	void dispatchCall(Call * c){
		Employees * e = getEmployee(c);
		c->setHandler(e);
		if(e != NULL){
			c->startcall();
		}
		else{
			callqueue[c->rank].push(c);
			say("PLEASE WAIT")
		}
	}
private:
	vector< Queue<Caller> > callqueue;
	vector< vector<Employees> > emp;
};

class Caller{
public:
	void Caller(Call *c){
		self->c = c;
	}
private:
	int rank;
	Employees * handler;
	Call * c;
};

class Call{
	
};