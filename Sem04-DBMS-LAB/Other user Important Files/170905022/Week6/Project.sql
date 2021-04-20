CREATE TABLE globalLedger(

	total_cash_flow Number(15, 2),
	savings_interest Number(4, 2),
	savings_amount Number(15, 2),
	loan_interest Number(4,2),
	loan_amount Number(16, 2),
	credit_amount Number(15, 2),
	debit_amount Number(15,2)
);

CREATE TABLE users(

	UIN INT,
	firstName VARCHAR(30),
	middleName VARCHAR(30),
	lastName VARCHAR(30),
	contact Number(10)
);
 ALTER TABLE users ADD CONSTRAINT uin_primary_key PRIMARY KEY(UIN);

CREATE TABLE Address(
	userID INT,
	houseNumber Number(3),
	houseName VARCHAR(20),
	street VARCHAR(10),
	city VARCHAR(10),
	state VARCHAR(10),
	country VARCHAR(10),
	pin Number(6),
	FOREIGN KEY(userID) REFERENCES users(UIN) ON DELETE CASCADE
);

CREATE TABLE BusinessAdress(
	companyID INT,
	buildingNumber Number(3),
	buildingName VARCHAR(20),
	street VARCHAR(10),
	city VARCHAR(10),
	state VARCHAR(10),
	country VARCHAR(10),
	pin Number(6),
	FOREIGN KEY(companyID) REFERENCES business(BID) ON DELETE CASCADE
);

	
CREATE TABLE bank(
	bankID INT,
	name VARCHAR(10),
	CONSTRAINT bank_id PRIMARY KEY(bankID)
);

CREATE TABLE business(
	BID INT,
	managerID INT,
	name VARCHAR(20),
	CONSTRAINT business_id PRIMARY KEY(BID)	
);

CREATE TABLE account(
	accountID INT,
	UIN INT,
	bankID INT,
	status VARCHAR(7),
	PRIMARY KEY(accountID),
	FOREIGN KEY(UIN) REFERENCES users(UIN),
	FOREIGN KEY(bankID) REFERENCES bank(bankID)
);

CREATE TABLE loan(
	LID INT,
	accountID INT,
	amount Number(10,2),
	interest Number(6, 2),
	status Varchar(7),
	collateral VARCHAR(10),
	trusteeID INT,
	startDate Date,
	endDate Date,
	PRIMARY KEY(LID),
	FOREIGN KEY(accountID) REFERENCES account(accountID),
	FOREIGN KEY(trusteeID) REFERENCES users(UIN)
);
		
CREATE TABLE deposits(
	DID INT,
	accountID INT,
	amount Number(15,2),
	interest Number(4, 2),
	startDate Date,
	endDate Date,
	status VARCHAR(8),
	PRIMARY KEY(DID),
	FOREIGN KEY(accountID) REFERENCES account(accountID)
);

CREATE TABLE credit(
	CID INT,
	accountID INT,
	amountAvaible Number(7,2),
	amountRemaining Number(7,2),
	startDate Date,
	dueDate Date,
	status VARCHAR(8),
	PRIMARY KEY(CID),
	FOREIGN KEY(accountID) REFERENCES account(accountID)
);

CREATE TABLE debit(
	debitID INT,
	accountID INT,
	amountAvaible Number(7,2),
	startDate Date,
	status VARCHAR(8),
	PRIMARY KEY(debitID),
	FOREIGN KEY(accountID) REFERENCES account(accountID)
);

CREATE TABLE businessAccount(
	BAID INT,
	BID INT,
	bankID INT,
	amount Number(15,2),
	startDate Date,
	endDate Date,
	status VARCHAR(8),
	PRIMARY KEY(BAID),
	FOREIGN KEY(BID) REFERENCES business(BID),
	FOREIGN KEY(bankID) REFERENCES bank(bankID)
);

CREATE TABLE contract(
	contractID INT,
	contractorID INT,
	contracteeID INT,
	title VARCHAR(50),
	terms VARCHAR2(500),
	amount Number(15,2),
	status VARCHAR(8),
	timestamp DATE,
	time_period NUMBER(6,2),
	PRIMARY KEY(contractID),
	FOREIGN KEY(contractorID) REFERENCES business(BID),
	FOREIGN KEY(contracteeID) REFERENCES business(BID)	
);

CREATE TABLE appointments(
	APPNID INT,
	UIN INT,
	BID INT,
	timestamp Date,
	status VARCHAR(8),
	PRIMARY KEY(APPNID),
	FOREIGN KEY(UIN) REFERENCES users(UIN),
	FOREIGN KEY(BID) REFERENCES business(BID)
);

