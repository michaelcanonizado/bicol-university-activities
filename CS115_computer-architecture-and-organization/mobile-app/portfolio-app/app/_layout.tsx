import { TextBody } from '@/components/text';
import './global.css';

import { Poppins_100Thin } from '@expo-google-fonts/poppins/100Thin';
import { Poppins_100Thin_Italic } from '@expo-google-fonts/poppins/100Thin_Italic';
import { Poppins_200ExtraLight } from '@expo-google-fonts/poppins/200ExtraLight';
import { Poppins_200ExtraLight_Italic } from '@expo-google-fonts/poppins/200ExtraLight_Italic';
import { Poppins_300Light } from '@expo-google-fonts/poppins/300Light';
import { Poppins_300Light_Italic } from '@expo-google-fonts/poppins/300Light_Italic';
import { Poppins_400Regular } from '@expo-google-fonts/poppins/400Regular';
import { Poppins_400Regular_Italic } from '@expo-google-fonts/poppins/400Regular_Italic';
import { Poppins_500Medium } from '@expo-google-fonts/poppins/500Medium';
import { Poppins_500Medium_Italic } from '@expo-google-fonts/poppins/500Medium_Italic';
import { Poppins_600SemiBold } from '@expo-google-fonts/poppins/600SemiBold';
import { Poppins_600SemiBold_Italic } from '@expo-google-fonts/poppins/600SemiBold_Italic';
import { Poppins_700Bold } from '@expo-google-fonts/poppins/700Bold';
import { Poppins_700Bold_Italic } from '@expo-google-fonts/poppins/700Bold_Italic';
import { Poppins_800ExtraBold } from '@expo-google-fonts/poppins/800ExtraBold';
import { Poppins_800ExtraBold_Italic } from '@expo-google-fonts/poppins/800ExtraBold_Italic';
import { Poppins_900Black } from '@expo-google-fonts/poppins/900Black';
import { Poppins_900Black_Italic } from '@expo-google-fonts/poppins/900Black_Italic';
import { useFonts } from '@expo-google-fonts/poppins/useFonts';

import { Tabs } from 'expo-router';
import { Image } from 'react-native';

export default function RootLayout() {
	let [fontsLoaded] = useFonts({
		Poppins_100Thin,
		Poppins_100Thin_Italic,
		Poppins_200ExtraLight,
		Poppins_200ExtraLight_Italic,
		Poppins_300Light,
		Poppins_300Light_Italic,
		Poppins_400Regular,
		Poppins_400Regular_Italic,
		Poppins_500Medium,
		Poppins_500Medium_Italic,
		Poppins_600SemiBold,
		Poppins_600SemiBold_Italic,
		Poppins_700Bold,
		Poppins_700Bold_Italic,
		Poppins_800ExtraBold,
		Poppins_800ExtraBold_Italic,
		Poppins_900Black,
		Poppins_900Black_Italic,
		Knicknack_Black: require('../assets/fonts/knicknack/Knicknack-Black.otf'),
		Knicknack_Bold: require('../assets/fonts/knicknack/Knicknack-Bold.otf'),
		Knicknack_Heavy: require('../assets/fonts/knicknack/Knicknack-Heavy.otf'),
		Knicknack_Medium: require('../assets/fonts/knicknack/Knicknack-Medium.otf'),
		Knicknack_Regular: require('../assets/fonts/knicknack/Knicknack-Regular.otf'),
	});

	if (!fontsLoaded) {
		return null;
	} else {
		return (
			<Tabs
				screenOptions={{
					/* Top Header */
					headerShown: true,
					headerStyle: {
						backgroundColor: '#E4E3DD',
					},
					headerTitleStyle: {
						fontFamily: 'Poppins_700Bold',
						fontSize: 18,
						color: '#000000',
					},
					headerTitleAlign: 'center',

					/* Bottom Tab */
					tabBarStyle: {
						backgroundColor: '#E4E3DD',
						height: 80,
					},
					tabBarLabelStyle: {
						fontFamily: 'Poppins_400Regular',
					},
					tabBarActiveTintColor: '#000000',
					tabBarInactiveTintColor: '#666d80',

					tabBarItemStyle: {
						paddingVertical: 5,
					},

					tabBarIconStyle: {
						marginBottom: 3,
					},

					tabBarLabel: ({ focused, color, children }) => (
						<TextBody
							style={{
								color,
								fontSize: focused ? 12 : 11,
								fontFamily: focused
									? 'Poppins_700Bold'
									: 'Poppins_400Regular',
							}}
						>
							{children}
						</TextBody>
					),
				}}
			>
				<Tabs.Screen
					name="index"
					options={{
						title: 'About',
						headerShown: false,
						tabBarIcon: ({ focused }) => (
							<Image
								source={
									focused
										? require('../assets/icons/green-active.png')
										: require('../assets/icons/green-inactive.png')
								}
								style={{
									width: 32,
									height: 32,
									resizeMode: 'contain',
								}}
							/>
						),
					}}
				/>
				<Tabs.Screen
					name="projects"
					options={{
						title: 'Projects',
						tabBarIcon: ({ focused }) => (
							<Image
								source={
									focused
										? require('../assets/icons/pink-active.png')
										: require('../assets/icons/pink-inactive.png')
								}
								style={{
									width: 32,
									height: 32,
									resizeMode: 'contain',
								}}
							/>
						),
					}}
				/>
				<Tabs.Screen
					name="experience"
					options={{
						title: 'Experience',
						tabBarIcon: ({ focused }) => (
							<Image
								source={
									focused
										? require('../assets/icons/blue-active.png')
										: require('../assets/icons/blue-inactive.png')
								}
								style={{
									width: 32,
									height: 32,
									resizeMode: 'contain',
								}}
							/>
						),
					}}
				/>
				<Tabs.Screen
					name="chat"
					options={{
						title: 'Chat',
						tabBarIcon: ({ focused }) => (
							<Image
								source={
									focused
										? require('../assets/icons/orange-active.png')
										: require('../assets/icons/orange-inactive.png')
								}
								style={{
									width: 32,
									height: 32,
									resizeMode: 'contain',
								}}
							/>
						),
					}}
				/>
			</Tabs>
		);
	}
}
