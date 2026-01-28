import { TextBody, TextDisplay, TextSub } from '@/components/text';
import { router, useLocalSearchParams } from 'expo-router';
import { useState } from 'react';
import { Image, Linking, ScrollView, TouchableOpacity, View } from 'react-native';
import { projects } from '.';
import ChevronLeft from '../../assets/images/chevron-left.svg';
import ExternalLink from '../../assets/images/external-link.svg';

export default function ProjectDetails() {
	const { titleId } = useLocalSearchParams<{ titleId: string }>();

	const [parentHeight, setParentHeight] = useState(0);
	const project = projects.find((p) => p.title === titleId);

	if (!project) return null;

	const { title, year, techStack, type, description, link, images } = project;

	const handlePress = async () => {
		const supported = await Linking.canOpenURL(link);
		if (supported) {
			await Linking.openURL(link);
		} else {
			console.warn(`Don't know how to open URL: ${link}`);
		}
	};

	return (
		<ScrollView
			contentContainerStyle={{ flexGrow: 1 }}
			className="bg-background p-4"
		>
			{/* Back Button */}
			<View className="flex flex-row justify-start mb-4">
				<TouchableOpacity
					onPress={() => router.back()}
					className="flex flex-row items-center justify-center gap-2 px-4 py-2 w-fit border border-muted rounded-lg"
				>
					<View className="flex flex-row items-center justify-center">
						<ChevronLeft color={'#666d80'} />
					</View>
					<TextBody className="mt-[1px]">Back</TextBody>
				</TouchableOpacity>
			</View>

			{/* Main content */}
			<View className="flex-1 rounded-xl">
				<View
					onLayout={(event) => {
						const { height } = event.nativeEvent.layout;
						setParentHeight(height);
					}}
					className="bg-muted w-full aspect-video rounded-xl relative"
				>
					<View
						style={{ height: parentHeight - 40 }}
						className="z-97 scale-[0.87] rotate-[-12deg] right-[73%] top-[53%] translate-x-1/2 -translate-y-1/2 absolute bg-white p-1 aspect-[2/3] rounded-xl"
					>
						<View className="w-full h-full bg-accent-green overflow-hidden rounded-lg">
							<Image
								source={images[2]}
								resizeMode="cover"
								className="w-full h-full object-center"
							/>
						</View>
					</View>
					<View
						style={{ height: parentHeight - 40 }}
						className="z-98 scale-[0.87] rotate-[12deg] right-[27%] top-[53%] translate-x-1/2 -translate-y-1/2 absolute bg-white p-1 aspect-[2/3] rounded-xl"
					>
						<View className="w-full h-full bg-accent-blue overflow-hidden rounded-lg">
							<Image
								source={images[1]}
								resizeMode="cover"
								className="w-full h-full object-center"
							/>
						</View>
					</View>
					<View
						style={{
							height: parentHeight - 40,
							shadowColor: '#000000',
							shadowOffset: { width: 0, height: 8 },
							shadowOpacity: 0.5,
							shadowRadius: 15,
							elevation: 5,
						}}
						className="z-99 scale-100 rotate-[0deg] top-[50%] right-[50%] drop-shadow-2xl translate-x-1/2 -translate-y-1/2 absolute bg-white p-1 aspect-[2/3] rounded-xl"
					>
						<View className="w-full h-full bg-accent-yellow overflow-hidden rounded-lg">
							<Image
								source={images[0]}
								resizeMode="cover"
								className="w-full h-full object-center"
							/>
						</View>
					</View>
				</View>

				<View className="mt-4">
					<TextDisplay>{title}</TextDisplay>
					<View>
						<TextSub>{year}</TextSub>
						<TextSub>{type}</TextSub>
						<TextSub>{techStack.join(', ')}</TextSub>
					</View>
					<TextBody className="mt-4">{description}</TextBody>
				</View>

				<View className="flex flex-row justify-center mt-8 mb-8">
					<TouchableOpacity
						onPress={handlePress}
						className="bg-accent-yellow pl-8 pr-7 py-4 rounded-full flex flex-row gap-1 items-end"
					>
						<TextDisplay className="text-[21px] text-background">
							View Project
						</TextDisplay>
						<ExternalLink color={'#F6F5F1'} />
					</TouchableOpacity>
				</View>
			</View>
		</ScrollView>
	);
}
