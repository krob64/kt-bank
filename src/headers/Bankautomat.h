#pragma once
class Bankautomat {

	private:

		double bargeld = 0.0;
		unsigned int automatID;  // erstmal nur deklariert, weil die ID von der Bank kommt

	public:

		Bankautomat(double startBetrag);
		~Bankautomat();


		int auszahlung(Bankkunde*, int betrag, unsigned int pin);

		double getBargeld();
		void setBargeld(double betrag);
        unsigned int getAutomatID();
        void setAutomatID(unsigned int nummer);



};
