import ImageCircle from '@/components/image/image-circle';
import ImageSquare from '@/components/image/image-square';
import { TextBody, TextDisplay, TextHeading, TextSub } from '@/components/text';
import { Dimensions, Image, ScrollView, View } from 'react-native';
import Clouds from '../assets/images/clouds.svg';

const technologiesBadge = [
	{
		backgroundColor: '#6DB33F',
		source: require('../assets/technologies/spring-boot.png'),
	},
	{
		backgroundColor: '#000000',
		source: require('../assets/technologies/nextjs.png'),
	},
	{
		backgroundColor: '#20232A',
		source: require('../assets/technologies/react.png'),
	},
	{
		backgroundColor: '#2D79C7',
		source: require('../assets/technologies/typescript.png'),
	},
	{
		backgroundColor: '#161D2D',
		source: require('../assets/technologies/tailwindcss.png'),
	},
	{
		backgroundColor: '#2F6792',
		source: require('../assets/technologies/postgresql.png'),
	},
	{
		backgroundColor: '#7A0C00',
		source: require('../assets/technologies/redis.png'),
	},
	{
		backgroundColor: '#000000',
		source: require('../assets/technologies/kafka.png'),
	},
	{
		backgroundColor: '#ffffff',
		source: require('../assets/technologies/git.png'),
	},
	{
		backgroundColor: '#066DA5',
		source: require('../assets/technologies/docker.png'),
	},
];

const followMeBadges = [
	{
		backgroundColor: '#000000',
		source: require('../assets/technologies/github.png'),
	},
	{
		backgroundColor: '#0274B3',
		source: require('../assets/technologies/linkdin.png'),
	},
];

export default function About() {
	const screenWidth = Dimensions.get('window').width;

	return (
		<ScrollView className="bg-background">
			<View className="bg-orange-500 h-[200px] relative">
				<View className="bg-emerald-500 w-full h-full absolute">
					<Image
						source={require('../assets/images/sun-rays.png')}
						className="h-full object-cover w-full"
					/>
				</View>
				<ImageCircle
					className="bg-background absolute bottom-0 right-1/2 translate-x-[50%] translate-y-[30%] z-[99]"
					source={require('../assets/images/self-1.jpg')}
				/>
				<View className="absolute bottom-[-10px] h-fit z-[98]">
					<Clouds
						color={'#F6F5F1'}
						className="w-full"
						width={screenWidth}
					/>
				</View>
			</View>
			<View className="mt-12 flex flex-col items-center">
				<View className="mx-2 w-full flex flex-col items-center gap-2">
					<View className="flex flex-col">
						<TextDisplay className="w-fit text-center">
							creator
						</TextDisplay>
						<TextDisplay className="w-fit text-center">
							problem-solver
						</TextDisplay>
						<TextDisplay className="w-fit text-center">
							software engineer
						</TextDisplay>
					</View>
					<TextBody className="text-center w-[75%]">
						Creating a digital experience that bridge aesthetics and
						functionality🚀
					</TextBody>
				</View>
				<View className="mt-[100px] w-full flex flex-col items-center gap-12 mx-auto">
					<View className="flex flex-row w-full h-[125px] relative">
						<ImageSquare
							className="right-[72%] translate-y-[-10%] absolute rotate-[-3deg]"
							source={require('../assets/images/self-3.jpg')}
						/>
						<ImageSquare
							className="right-[48%] translate-y-[4%] absolute rotate-[-8deg]"
							source={require('../assets/images/self-5.jpg')}
						/>
						<ImageSquare
							className="right-[25%] translate-y-[-10%] absolute rotate-[5deg]"
							source={require('../assets/images/self-7.jpg')}
						/>
						<ImageSquare
							className="right-[3%] -translate-y-[-5%] absolute rotate-[-8deg]"
							source={require('../assets/images/self-6.jpg')}
						/>
						<ImageSquare
							className="right-[-20%] translate-y-[-5%] absolute rotate-[-0deg]"
							source={require('../assets/images/self-4.jpg')}
						/>
					</View>
					<View className="mx-2 w-[75%] flex flex-col items-center gap-2">
						<TextHeading className="text-center">
							Looking for a developer who can develop things you want
							to get developed? 🧑‍💻
						</TextHeading>
						<TextBody className="text-center">
							Your search ends here! With my knowledge in software
							engineering, you'll get a product that sets you apart!
						</TextBody>
					</View>
				</View>
				<View className="mt-[75px] mb-[75px] w-full flex flex-col items-center">
					<View className="w-full h-[400px] relative">
						<View className="size-[250px] z-[99] absolute top-0 left-[-15%]">
							<Image
								resizeMode="contain"
								source={require('../assets/images/character-cloud-black.png')}
								className="h-full w-full object-center"
							/>
						</View>
						<View className="size-[40px] z-[99] absolute top-[17%] left-[40%] rotate-[8deg] ">
							<Image
								resizeMode="contain"
								source={require('../assets/images/arrow.png')}
								className="h-full w-full object-center"
							/>
						</View>
						<View className="size-[75px] z-[99] absolute bottom-[52%] right-[12%] rotate-[8deg] ">
							<Image
								resizeMode="contain"
								source={require('../assets/images/chat.png')}
								className="h-full w-full object-center"
							/>
						</View>
						<View className="size-[250px] z-[99] absolute bottom-0 right-[-10%]">
							<Image
								resizeMode="contain"
								source={require('../assets/images/character-cloud-yellow.png')}
								className="h-full w-full object-center"
							/>
						</View>
					</View>
					<View className="w-[60%] gap-2 flex flex-col items-center">
						<TextHeading className="text-center">
							Nice to meet you!👋
						</TextHeading>
						<TextBody className="text-center">
							{`I'll bring your vision to life and make a difference`}
						</TextBody>
					</View>
				</View>
				<View className="mt-[40px] w-[90%] flex flex-col gap-4 m-4">
					<View className="flex flex-row gap-4">
						<View className="aspect-square w-[50%] bg-white p-2 rounded-3xl">
							<View className="aspect-square  bg-accent-yellow rounded-2xl  overflow-visible relative">
								<View
									style={{ width: screenWidth * 0.45 }}
									className="overflow-visible h-[250px]  absolute bottom-[-5%] right-[0%] w-fit"
								>
									<Image
										resizeMode="cover"
										source={require('../assets/images/self-2.png')}
										className="h-full w-full object-bottom"
									/>
								</View>
							</View>
						</View>
						<View className="flex flex-col w-1/2 justify-end">
							<View className="flex flex-row gap-1 items-center">
								<TextDisplay className="text-[21px] text-accent-yellow">
									mikey
								</TextDisplay>
								<View className="size-[25px]">
									<Image
										source={require('../assets/images/verified-badge.png')}
										className="h-full object-contain w-full object-center"
									/>
								</View>
							</View>
							<View className="flex flex-col items-start">
								<TextSub>@michaelcanonizado</TextSub>
								<TextSub>Albay, Philippines</TextSub>
							</View>
						</View>
					</View>
					<View className="flex flex-col gap-4">
						<TextHeading>
							I am a self-taught software engineer based in the
							Philippines!🏖️
						</TextHeading>
						<View className="flex flex-col gap-2">
							<TextBody>
								You can call me mikey. I am a junior Computer Science
								student with 5 years of experience in software
								engineering.
							</TextBody>
							<TextBody>
								{`I specialize in backend development and systems
								architecture that's robust and scalable.`}
							</TextBody>
							<TextBody>
								{`I'll transform your ideas into a system that elevates
								your business. My strong work ethic and discipline
								set me apart as a developer you can rely on!`}
							</TextBody>
						</View>
					</View>
				</View>
				<View className="mt-[40px] w-full flex flex-col items-center gap-4">
					<View className="mx-auto">
						<TextHeading>Technologies 💻</TextHeading>
					</View>
					<View
						className="flex justify-center flex-row flex-wrap gap-4 h-fit mx-auto "
						style={{ width: screenWidth - 32 }}
					>
						{technologiesBadge.map((tech, index) => {
							return (
								<View
									key={index}
									className="rounded-2xl aspect-square size-[55px] p-2 flex flex-col items-center justify-center overflow-hidden"
									style={{ backgroundColor: tech.backgroundColor }}
								>
									<View className="w-full h-full">
										<Image
											source={tech.source}
											resizeMode="contain"
											className="w-full h-full object-center"
										/>
									</View>
								</View>
							);
						})}
					</View>
					<View className="w-[75%]">
						<TextBody className="text-center">
							I utilize proven technologies to deliver high-perfomance
							and scalable solutions.
						</TextBody>
					</View>
				</View>
				<View className="mt-[40px] mb-4 w-full flex flex-col gap-4">
					<View className="bg-muted rounded-2xl flex flex-row items-center justify-between px-4 py-8 mx-4">
						<View className="">
							<TextHeading>Follow Me 📩</TextHeading>
						</View>
						<View className="flex flex-row gap-2">
							{followMeBadges.map((badge, index) => {
								return (
									<View
										style={{
											backgroundColor: badge.backgroundColor,
										}}
										key={index}
										className="size-[35px] p-1 rounded-full flex items-center justify-center overflow-hidden"
									>
										<Image
											resizeMode="contain"
											className="w-full h-full"
											source={badge.source}
										/>
									</View>
								);
							})}
						</View>
					</View>
					<View className="bg-muted rounded-2xl px-4 py-8 mx-4 flex flex-col items-center justify-center gap-2">
						<View className="flex flex-col gap-0">
							<TextBody className="text-center">
								CS115 Project
							</TextBody>
							<TextBody className="text-center">
								Computer Architecture and Organization
							</TextBody>
						</View>
						<View className="flex flex-col gap-0">
							<TextSub className="text-center">
								BS Computer Science 3A
							</TextSub>
							<TextSub className="text-center">
								Michael Xavier Canonizado
							</TextSub>
							<TextSub className="text-center">
								michaelxaviercanonizado@gmail.com
							</TextSub>
						</View>
					</View>
				</View>
			</View>
		</ScrollView>
	);
}
