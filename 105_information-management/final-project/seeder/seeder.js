const mysql = require('mysql2/promise');
const { faker } = require('@faker-js/faker');
const fs = require('fs');
const csv = require('csv-parser');

const results = [];

const INSERT_COUNT = 50;

// async function seedDatabase() {
// 	const connection = await mysql.createConnection({
// 		host: 'localhost',
// 		user: 'root',
// 		password: '',
// 		database: 'iflair-dental-clinic-management-system',
// 	});

// 	console.log('Connected to MySQL.');

// 	const [rows] = await connection.execute('SELECT * FROM employee LIMIT 10');
// 	console.log(rows);

// 	console.log(`${INSERT_COUNT} fake records inserted.`);
// 	await connection.end();
// }

// seedDatabase().catch(console.error);


