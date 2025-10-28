import {
	TimelineBody,
	TimelineContainer,
	TimelineHeading,
	TimelineSub,
} from '@/components/timeline';
import React from 'react';
import { Image, ScrollView, View } from 'react-native';

function TimelineSeparator({ children }: ComponentChildrenProp) {
	return (
		<View className="w-full my-4 relative flex flex-col justify-center items-center">
			<View className="w-[2px] rounded-full  h-[80px] bg-foreground-100" />
			<View className="size-[10px] bg-foreground-100 rounded-full" />
			{children}
		</View>
	);
}

export default function Experience() {
	return (
		<ScrollView className="bg-background">
			<View className="flex flex-col justify-start items-center">
				<View className="w-full mb-4 relative flex flex-col justify-center items-center">
					<View className="w-[2px] rounded-full  h-[20px] bg-foreground-100" />
					<View className="size-[10px] bg-foreground-100 rounded-full" />
				</View>
				<TimelineContainer>
					<TimelineHeading>The start of my journey 🚀</TimelineHeading>
					<TimelineSub>2020 - 2021</TimelineSub>
					<TimelineBody>
						My journey into the world of programming started with the
						renowned Harvard CS50 course. This foundational experience
						became my gateway drug to programming.
					</TimelineBody>
				</TimelineContainer>
				<TimelineSeparator>
					<View className="size-[125px] z-[99] absolute bottom-[-10%] left-[5%]">
						<Image
							resizeMode="contain"
							source={require('../assets/images/character-cloud-yellow-2.png')}
							className="h-full w-full object-center"
						/>
					</View>
				</TimelineSeparator>
				<TimelineContainer>
					<TimelineHeading>Freelancing 👨‍💻</TimelineHeading>
					<TimelineSub>2022 - 2023</TimelineSub>
					<TimelineBody>
						Eager to put my skills to the test, I challenged myself to
						start freelancing. Working with diverse clients and projects
						honed my ability to communicate effectively and deliver
						top-notch solutions.
					</TimelineBody>
				</TimelineContainer>
				<TimelineSeparator>
					<View className="size-[125px] z-[99] absolute bottom-[-10%] right-[0%]">
						<Image
							resizeMode="contain"
							source={require('../assets/images/character-cloud-black-2.png')}
							className="h-full w-full object-center"
						/>
					</View>
				</TimelineSeparator>
				<TimelineContainer>
					<TimelineHeading>Academic Adventure 🎓</TimelineHeading>
					<TimelineSub>2023 - Present</TimelineSub>
					<TimelineBody>
						Taking my passion for programming to the next level, I
						embarked on a formal education journey by pursuing a degree
						in Computer Science at Bicol University. To further enhance
						my skills, I became actively involved in organizations such
						as Google Developer Groups on Campus and College Student
						Council
					</TimelineBody>
				</TimelineContainer>
			</View>
		</ScrollView>
	);
}
