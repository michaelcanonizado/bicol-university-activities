/** @type {import('tailwindcss').Config} */
module.exports = {
	// NOTE: Update this to include the paths to all files that contain Nativewind classes.
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
			},
		},
	},
	plugins: [],
};
