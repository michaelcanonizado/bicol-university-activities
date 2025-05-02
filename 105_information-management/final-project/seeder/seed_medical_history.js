const mysql = require('mysql2/promise');
const { faker } = require('@faker-js/faker');
const fs = require('fs');

async function seed_database() {
	const database = 'iflair-dental-clinic-management-system';
	const table = 'medical_history';

	// Establish SQL connection
	const connection = await mysql.createConnection({
		host: 'localhost',
		user: 'root',
		password: '',
		database,
		connectTimeout: 10000,
	});
	console.log('Connected to MySQL.');

	// Generate rows with random data
	const rows = [];
	const insertCount = 50;
	console.log(`Generating ${insertCount} random ${table} data...`);
	for (let i = 0; i < insertCount; i++) {}

	// Output generated rows
	console.log(rows);

	// Delete all existing rows in table
	console.log(`Deleting all rows in:  ${database}.${table}...`);
	await connection.query('DELETE FROM patient');
	console.log(`Deleted all rows in:  ${database}.${table}!`);

	// Reset primary key auto increment to 1
	console.log(`Reseting AUTO_INCREMENT to 1 in:  ${database}.${table}...`);
	await connection.query('ALTER TABLE patient AUTO_INCREMENT = 1');
	console.log(`Reseted AUTO_INCREMENT to 1 in:  ${database}.${table}...`);

	// Insert the generated data into the database
	console.log(`Inserting ${insertCount} generated ${table} data...`);
	await connection.query(
		`INSERT INTO ${table} (first_name, middle_name, last_name, gender, contact_no, date_of_birth, age, religion, nationality, occupation, guardian_name, guardian_occupation, street, province, municipality, barangay, zip_code, civil_status) VALUES ?`,
		[rows]
	);
	console.log('Seed successful!');

	// Generate the raw SQL of the actions above  for logging
	const raw_sql =
		`DELETE FROM ${table};\n` +
		`ALTER TABLE ${table} AUTO_INCREMENT = 1;\n\n` +
		`INSERT INTO ${table} (patient_id, blood_type, allergies, chronic_illnesses, current_medication, past_surgeries, bleeding_disorders, heart_condition, respiratory_issues, autoimmune_disease, is_pregnant, gum_disease_history, genetic_conditions, oral_cancer_history)  VALUES\n\n` +
		rows
			.map((row) => `(${row.map((v) => mysql.escape(v)).join(', ')})`)
			.join(',\n\n') +
		';';

	fs.writeFileSync(`queries/${table}.txt`, raw_sql, { flag: 'w' });

	// Terminate connection
	await connection.end();
}

seed_database().catch(console.error);
