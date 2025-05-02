const mysql = require('mysql2/promise');
const { faker } = require('@faker-js/faker');
const fs = require('fs');
const csv = require('csv-parser');

const MALE_FIRST_NAMES = fs
	.readFileSync('csv/male_first_names.csv', 'utf8')
	.split('\n')
	.map((name) => name.trim())
	.filter((name) => name.length > 0);

const FEMALE_FIRST_NAMES = fs
	.readFileSync('csv/female_first_names.csv', 'utf8')
	.split('\n')
	.map((name) => name.trim())
	.filter((name) => name.length > 0);

const LAST_NAMES = fs
	.readFileSync('csv/last_names.csv', 'utf8')
	.split('\n')
	.map((name) => name.trim())
	.filter((name) => name.length > 0);

const MIDDLE_NAMES = fs
	.readFileSync('csv/middle_names.csv', 'utf8')
	.split('\n')
	.map((name) => name.trim())
	.filter((name) => name.length > 0);

const OCCUPATIONS = [
	'doctor',
	'engineer',
	'teacher',
	'nurse',
	'artist',
	'scientist',
	'lawyer',
	'architect',
	'developer',
	'designer',
	'chef',
	'journalist',
	'plumber',
	'mechanic',
	'farmer',
];

const MUNICIPALITIES = {
	albay: [
		'bacacay',
		'camalig',
		'daraga',
		'guinobatan',
		'jovellar',
		'libon',
		'malilipot',
		'malinao',
		'manito',
		'oanob',
		'pio duran',
		'polangui',
		'rapu-rapu',
		'sto. domingo',
		'tiwi',
	],
	camarinesNorte: [
		'basud',
		'capalonga',
		'jose panganiban',
		'labo',
		'mercedes',
		'paracale',
		'san lorenzo ruiz',
		'san vicente',
		'sta. elena',
		'talisay',
		'vinzons',
	],
	camarinesSur: [
		'baao',
		'balatan',
		'bato',
		'bombon',
		'buhi',
		'bula',
		'cabusao',
		'calabanga',
		'camaligan',
		'canaman',
		'caramoan',
		'del gallego',
		'gainza',
		'garchitorena',
		'goa',
		'lupi',
		'magarao',
		'milaor',
		'minalabac',
		'nabua',
		'ocampo',
		'pamplona',
		'pasacao',
		'presentacion',
		'ragay',
		'sagnay',
		'san fernando',
		'san jose',
		'sipocot',
		'siruma',
		'tigaon',
		'tinambac',
	],
	catanduanes: [
		'bagamanoc',
		'baras',
		'bato',
		'caramoran',
		'gigmoto',
		'pandan',
		'panganiban',
		'san andres',
		'san miguel',
		'viga',
		'virac',
	],
	masbate: [
		'aroroy',
		'baleno',
		'balud',
		'batuan',
		'cataingan',
		'cawayan',
		'claveria',
		'dimasalang',
		'esperanza',
		'mandaon',
		'milagros',
		'mobo',
		'monreal',
		'palanas',
		'pio v. corpuz',
		'plaridel',
		'san fernando',
		'san jacinto',
		'san pascual',
		'uason',
	],
	sorsogon: [
		'barcelona',
		'bulan',
		'bulusan',
		'casiguran',
		'castilla',
		'donsol',
		'gubat',
		'irosin',
		'juban',
		'magallanes',
		'matnog',
		'pilar',
		'prieto diaz',
		'santa magdalena',
	],
};

const PROVINCES = Object.keys(MUNICIPALITIES);

const BARANGAYS = [
	'barangay 1',
	'barangay 2',
	'barangay 3',
	'barangay 4',
	'barangay 5',
	'barangay 6',
	'barangay 7',
	'barangay 8',
	'barangay 9',
	'barangay 10',
	'barangay 11',
	'barangay 12',
	'barangay 13',
	'barangay 14',
	'barangay 15',
];

const CIVIL_STATUSES = ['single', 'married', 'divorced', 'widower/widowed'];

function calculate_age(birthDate) {
	const today = new Date();
	const birth = new Date(birthDate);

	let age = today.getFullYear() - birth.getFullYear();
	const hasHadBirthdayThisYear =
		today.getMonth() > birth.getMonth() ||
		(today.getMonth() === birth.getMonth() &&
			today.getDate() >= birth.getDate());

	if (!hasHadBirthdayThisYear) {
		age--;
	}

	return age;
}

async function seed_database() {
	const connection = await mysql.createConnection({
		host: 'localhost',
		user: 'root',
		password: '',
		database: 'iflair-dental-clinic-management-system',
		connectTimeout: 10000,
	});

	console.log('Connected to MySQL.');

	const patients = [];
	const insertCount = 25;
	for (let i = 0; i < insertCount; i++) {
		const gender = Math.random() < 0.5 ? 'male' : 'female';

		const first_name =
			gender == 'male'
				? MALE_FIRST_NAMES[
						Math.floor(Math.random() * MALE_FIRST_NAMES.length)
				  ]
				: FEMALE_FIRST_NAMES[
						Math.floor(Math.random() * FEMALE_FIRST_NAMES.length)
				  ];

		const middle_name_index = Math.floor(Math.random() * MIDDLE_NAMES.length);
		let middle_name;
		// Add chance 1/6 chance for a patient to get no middle name
		if (middle_name_index < MIDDLE_NAMES.length / 6) {
			middle_name = null;
		} else {
			middle_name = MIDDLE_NAMES[middle_name_index];
		}

		const last_name = LAST_NAMES[Math.floor(Math.random() * LAST_NAMES.length)];

		const contact_no = faker.phone.number({ style: 'international' });

		const date_of_birth = faker.date.birthdate({ min: 5, max: 90, mode: 'age' });

		const age = calculate_age(date_of_birth);

		const religion = 'christian';

		const nationality = 'filipino';

		let occupation = null;
		if (age > 22) {
			occupation = OCCUPATIONS[Math.floor(Math.random() * OCCUPATIONS.length)];
		}

		let guardian_name = null;
		let guardian_occupation = null;
		if (age < 18) {
			const guardian_first_name =
				Math.random() < 0.5
					? MALE_FIRST_NAMES[
							Math.floor(Math.random() * MALE_FIRST_NAMES.length)
					  ]
					: FEMALE_FIRST_NAMES[
							Math.floor(Math.random() * FEMALE_FIRST_NAMES.length)
					  ];

			const guardian_middle_name = (middle_name =
				MIDDLE_NAMES[Math.floor(Math.random() * MIDDLE_NAMES.length)]);

			const guardian_last_name = last_name;

			guardian_name =
				guardian_first_name +
				' ' +
				guardian_middle_name +
				' ' +
				guardian_last_name;

			guardian_occupation =
				OCCUPATIONS[Math.floor(Math.random() * OCCUPATIONS.length)];
		}

		const street =
			Math.random() < 0.3 ? null : faker.location.secondaryAddress();

		const province = PROVINCES[Math.floor(Math.random() * PROVINCES.length)];

		const municipality =
			MUNICIPALITIES[province][
				Math.floor(Math.random() * MUNICIPALITIES[province].length)
			];

		const barangay = BARANGAYS[Math.floor(Math.random() * BARANGAYS.length)];

		const zip_code = faker.number.int({
			min: 4400,
			max: 4700,
		});

		const civil_status =
			age > 30
				? CIVIL_STATUSES[Math.floor(Math.random() * CIVIL_STATUSES.length)]
				: 'single';

		patients.push([
			first_name,
			middle_name,
			last_name,
			gender,
			contact_no,
			date_of_birth,
			age,
			religion,
			nationality,
			occupation,
			guardian_name,
			guardian_occupation,
			street,
			province,
			municipality,
			barangay,
			zip_code,
			civil_status,
		]);
	}

	console.log(patients);

	await connection.query(
		'INSERT INTO patient (first_name, middle_name, last_name, gender, contact_no, date_of_birth, age, religion, nationality, occupation, guardian_name, guardian_occupation, street, province, municipality, barangay, zip_code, civil_status) VALUES ?',
		[patients]
	);

	await connection.end();
}

seed_database().catch(console.error);
