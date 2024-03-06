#pragma once
class Bankautomat {

	private:

		double bargeld = 0.0;
		unsigned int automatID;  // erstmal nur deklariert, weil die ID von der Bank kommt

	public:

		Bankautomat(double startBetrag);
		~Bankautomat();


		int auszahlung(girokonto* girokonto, kreditkarte* kreditkarte, int auszahlungsBetrag);
		
		double getBargeld();
		void setBargeld(double betrag);
        unsigned int getAutomatID();
        void setAutomatID(unsigned int nummer);



};
