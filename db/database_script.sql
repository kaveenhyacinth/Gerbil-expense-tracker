CREATE TABLE account (
	_id 					INTEGER,
	account_name 	TEXT 			NOT NULL,
	balance 			TEXT 	NOT NULL DEFAULT 0,
	PRIMARY KEY(_id AUTOINCREMENT)
);

CREATE TABLE category (
	_id 	INTEGER 	PRIMARY KEY,
	type 	TEXT 			NOT NULL,
	ref 	CHAR 			NOT NULL
);

CREATE TABLE record (
	_id 				INTEGER 	PRIMARY KEY,
	account_id 	INTEGER 	NOT NULL,
	record_type TEXT 			CHECK(record_type IN ('EXPENSE', 'INCOME')) NOT NULL DEFAULT 'INCOME',
	category 		INTEGER 	NOT NULL DEFAULT 0,
	amount 			TEXT 			NOT NULL DEFAULT "0.00",
	date 				DATE 			NOT NULL,
	FOREIGN KEY(account_id) REFERENCES account(id) ON DELETE CASCADE,
	FOREIGN KEY(category) REFERENCES category(id) ON DELETE CASCADE
);


INSERT INTO category (type, ref) VALUES
("Other", 'E'),
("Food", 'E'),
("Social Life", 'E'),
("Self Development", 'E'),
("Transportation", 'E'),
("Culture", 'E'),
("Household", 'E'),
("Apparel", 'E'),
("Beauty", 'E'),
("Health", 'E'),
("Education", 'E'),
("Utilities", 'E'),
("Rentals", 'E'),
("Stores", 'E'),
("Gift", 'E'),
("Other", 'I'),
("Salary", 'I'),
("Allowance", 'I'),
("Petty Cash", 'I'),
("Bonus", 'I'),
("Commision", 'I'),
("Interest", 'I'),
("Dividends", 'I'),
("Sales", 'I'),
("Gift", 'I');