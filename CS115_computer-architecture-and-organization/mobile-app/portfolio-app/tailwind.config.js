/** @type {import('tailwindcss').Config} */
module.exports = {
	content: ['./app/**/*.{js,jsx,ts,tsx}', './components/**/*.{js,jsx,ts,tsx}'],
	presets: [require('nativewind/preset')],
	theme: {
		extend: {
			colors: {
				background: '#F6F5F1',
				'foreground-100': '#000000',
				'foreground-200': '#666d80',
				muted: '#E4E3DD',
				'muted-foreground': '#666d80',
				'accent-yellow': '#FCAC0F',
				'accent-green': '#00A652',
				'accent-blue': '#0061EE',
				'accent-orange': '#FB5500',
				'accent-pink': '#FF77B9',
			},
		},
	},
	plugins: [],
};
