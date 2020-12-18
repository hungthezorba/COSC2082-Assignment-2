//
// Created by Hung Nguyen on 26/04/19.
//

#ifndef COSC2082_ASSIGNMENT_2_ITEM_H
#define COSC2082_ASSIGNMENT_2_ITEM_H
#include "string"

using namespace std;

class Item {
    private:
        string id;
        string title;
        string rentalType;
        string loanType;
        int numberOfCopies;
        double rentalFee;
        bool rentalStatus;
    public:
        const string &getId() const;

        void setId(const string &id);

        const string &getTitle() const;

        void setTitle(const string &title);

        const string &getRentalType() const;

        void setRentalType(const string &rentalType);

        const string &getLoanType() const;

        void setLoanType(const string &loanType);

        int getNumberOfCopies() const;

        void setNumberOfCopies(int numberOfCopies);

        double getRentalFee() const;

        void setRentalFee(double rentalFee);

        bool isRentalStatus() const;

        void setRentalStatus(bool rentalStatus);

        Item();
        Item(string id, string title, string rentalType, string loanType, int numberOfCopies,double rentalFee);
        bool renting();
        bool returning();
};


#endif //COSC2082_ASSIGNMENT_2_ITEM_H
