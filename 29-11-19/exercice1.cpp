#include <iostream>
using namespace std;

class Etudiant{
    string nom,prenom;
    static int cons;
    int nbNotes,matricule;
    float *notes;
public:
    Etudiant(){};
    Etudiant(string n,string p){
        nom = n;
        prenom = p;
        matricule = ++cons;
    }
    Etudiant(Etudiant & e){
        nom = e.nom;
        prenom = e.prenom;
        matricule = ++cons;
        delete notes;
        nbNotes = e.nbNotes;
        notes = new float[nbNotes];
        for (int i = 0; i < nbNotes; i++)
        {
            notes[i] = e.notes[i];
        }
    }
    void setNom(string n){
        nom = n;
    }
    string getNom(){
        return nom;
    }
    int getId(){
        return matricule;
    }
    void setPrenom(string p){
        prenom = p;
    }
    void saisieNotes(int nbN){
        nbNotes = nbN;
        notes = new float[nbNotes];
        for (int i = 0; i < nbNotes; i++)
        {
            cout << "note numero " << i+1 << endl;
            cin >> notes[i];
        }
    }
    void setNotes(int pos, float value){
        notes[pos] = value;
    }
    void afficher(){
        cout << "nom : " << nom << "\n prenom : " << prenom << "\n Notes : \n";
        for (int i = 0; i < nbNotes; i++)
        {
            cout << "note numero " << i+1  << " : " << notes[i] << endl;
        }
    }
    float getMoyenne(){
        float sum{0};
        for (int i = 0; i < nbNotes; i++)
        {
            sum+=notes[i];
        }
        return sum/nbNotes;
    }
    float getMaxNote(){
        float maxi = notes[0];
        for (int i = 0; i < nbNotes; i++)
        {
            if (notes[i] > maxi)
            {
                maxi = notes[i];
            }
        }
        return maxi;
    }
    float getMinNote(){
        float mini = notes[0];
        for (int i = 0; i < nbNotes; i++)
        {
            if (notes[i] < mini)
            {
                mini = notes[i];
            }
        }
        return mini;
    }
    int getNbNotes(){
        return nbNotes;
    }
    float *getNotes(){
        return notes;
    }
    ~Etudiant(){
        delete notes;
    }
};
int Etudiant::cons = 0;

class Responsable{
    string nom,prenom;
    int tel;
public:
    Responsable(){}
    Responsable(string n,string p){
        nom = n;
        prenom = p;
    }
    string getNom(){
        return nom;
    }
};

class Filiere{
    static int comp;
    string nomF;
    bool accr;
    int id,nbEtud{0};
    Responsable res;
    Etudiant *ets;
public:
    Filiere(){};
    Filiere(string n,bool ac,Responsable r){
        nomF = n;
        accr = ac;
        res = r;
        id = ++comp;
    }
    Filiere(Filiere & f){
        delete ets;
        nbEtud = f.nbEtud;
        ets = new Etudiant[nbEtud];
        for (int i = 0; i < nbEtud; i++)
        {
            ets[i] = f.ets[i];
        }
    }
    int getNbEtud(){
        return nbEtud;
    }
    void saisie(int n){
        nbEtud = n;
        ets = new Etudiant[nbEtud];
        for (int i = 0; i < nbEtud; i++)
        {
            string n,p;
            cout << "Entrez le nom de l'etudiant numero : " << i+1 << endl;
            cin >> n;
            cout << "Entrez le prenom de l'etudiant numero : " << i+1 << endl;
            cin >> p;
            Etudiant tmp(n,p);
            ets[i] = tmp;
            ets[i].saisieNotes(4);
        }
        
    }
    void afficher(){
        cout << "Filiere : " << nomF << endl;
        cout << "Responsable : " << res.getNom() << endl;
        cout << "Accridite : " << accr << endl;
        cout << "================================" << endl;
        cout << "Liste des etudiants : " << endl;
        cout << "================================" << endl;
        for (int i = 0; i < nbEtud; i++)
        {
            ets[i].afficher();
            cout << "================================" << endl;
        }
    }
    Etudiant getMajoran(){
        Etudiant maj = ets[0];
        for (int i = 1; i < nbEtud; i++)
        {
            if (ets[i].getMoyenne() > maj.getMoyenne())
            {
                maj = ets[i];
            }
        }
        return maj;
    }
    float getMaxNote(){
        float maxn = ets[0].getMaxNote();
        for (int i = 1; i < nbEtud; i++)
        {
           if (ets[i].getMaxNote() > maxn)
           {
               maxn = ets[i].getMaxNote();
           }
        }
        return maxn;
    }
    float getPourcentageAdmis(){ //// TODO !!
        int nbAdmis = 0;
        float prc;
        for (int i = 0; i < nbEtud; i++)
        {
            if ((ets[i].getMoyenne() >= 10)&&(ets[i].getMinNote()>5))
            {
                nbAdmis++;
            }
        }
        prc = (float)nbAdmis/nbEtud;
        return prc*100;
    }
    float getPourcentageEleminer(){
        int nbElim = 0;
        for (int i = 0; i < nbEtud; i++)
        {
            if ((ets[i].getMoyenne() < 10) && (ets[i].getMinNote()<=5))
            {
                nbElim++;
            }
        }
        return ((float)nbElim/(float)nbEtud)*100;
    }
    Etudiant *getEts(){
        return ets;
    }
    ~Filiere(){
        delete ets;
    }
};
int Filiere::comp = 0;

class Faculte{
    string nom_fac,adress_fac;
    int nbFil;
    Filiere *fls;
public:
    Faculte(string n, string ad){
        nom_fac = n;
        adress_fac = ad;
    }
    void saisie(int n){
        nbFil = n;
        string nf,nr,pr;
        bool ac;
        fls = new Filiere[nbFil];
        for (int i = 0; i < nbFil; i++)
        {
            cout << "Donner le nom du filiere : " << endl;
            cin >> nf;
            cout << "Donner le nom et prenom du responsable du filiere : " << endl;
            cin >> nr >> pr;
            cout << "Accredite ?" << endl;
            cin >> ac;
            Responsable tmpr(nr,pr);
            Filiere tmp(nf,ac,tmpr);
            fls[i] = tmp;
        }
    }
    Filiere getMeilleurFiliere(){
        Filiere mf = fls[0];
        for (int i = 0; i < nbFil; i++)
        {
            if (fls[i].getPourcentageAdmis() > mf.getPourcentageAdmis())
            {
                mf = fls[i];
            }
        }
        return mf;
    }
    Etudiant getMajoranEcole(){
        Etudiant maje = fls[0].getEts()[0];
        for (int i = 0; i < nbFil; i++)
        {
            if (fls[i].getMajoran().getMoyenne() > maje.getMoyenne())
            {
                maje = fls[i].getMajoran();
            }
        }
        return maje;
    }
    int getNbElimine(Filiere f){
        return (f.getPourcentageEleminer()*f.getNbEtud())/100;
    }
    void listElimine(){
        cout << "Liste des etudiants elimine : " << endl;
        for (int i = 0; i < nbFil; i++)
        {
            if ((fls[i].getEts()[i].getMoyenne() < 10)&&(fls[i].getEts()[i].getMinNote()<5))
            {
                fls[i].getEts()[i].afficher();
            }
        }
    }
    Etudiant exist(int id){
        for (int i = 0; i < nbFil; i++)
        {
            for (int j = 0; j < fls[i].getNbEtud(); i++)
            {
                if (fls[i].getEts()[j].getId() == id)
                {
                    return fls[i].getEts()[j];
                }
            }
        }
    }
    void modifierNote(int id){
        int n;
        float val;
        cout << "Entrer le numero du note a modifier " << endl;
        for (int i = 0; i < exist(id).getNbNotes(); i++)
        {
            cout << "Numero : " << i << exist(id).getNotes()[i] << endl;
        }
        cin >> n;
        cout << "Entrer la nouvelle note " << endl;
        cin >> val;
        exist(id).setNotes(n,val);
    }
    void afficherEtudChar(char c){
        for (int i = 0; i < nbFil; i++)
        {
            for (int j = 0; j < fls[i].getNbEtud(); i++)
            {
                if (c == fls[i].getEts()[j].getNom()[0])
                {
                    cout << fls[i].getEts()[j].getNom() << endl;
                }
            }
        } 
    }
};

int main(){
    Responsable r("nomresp","prenomresp");
    Filiere f("info",true,r);
    f.saisie(2);
    f.afficher();
    cout << "Majoran : " << f.getMajoran().getNom() << endl;
    cout << "Max note : " << f.getMaxNote() << endl;
    cout << "Pourcentage admis : " << f.getPourcentageAdmis() << "%" << endl;
    cout << "Pourcentage elimine : " << f.getPourcentageEleminer() << "%" << endl;
}