import { TextBody, TextSub } from '@/components/text';
import { Link } from 'expo-router';
import { Image, ScrollView, TouchableOpacity, View } from 'react-native';
import ChevronRight from '../../assets/images/chevron-right.svg';

export type Project = {
	id: string;
	title: string;
	year: number;
	techStack: string[];
	type: string;
	description: string;
	link: string;
	images: any[];
	thumbnail: any;
};

export const projects: Project[] = [
	{
		id: '1',
		title: 'Minder💸',
		year: 2023,
		techStack: ['NextJS', 'TailwindCSS', 'MongoDB'],
		type: 'Fullstack',
		description:
			'Due to my lack of knowledge in Excel, I created a personal finance tracker. Since I am more skilled in web development, I created a website that tracks my finances and provides analytics.',
		link: 'https://github.com/michaelcanonizado/minder',
		images: [
			require('../../assets/images/self-4.jpg'),
			require('../../assets/images/self-5.jpg'),
			require('../../assets/images/self-6.jpg'),
		],
		thumbnail: require('../../assets/images/self-6.jpg'),
	},
];

export default function ProjectsList() {
	return (
		<ScrollView className="bg-background flex flex-col gap-4">
			<View className="bg-muted flex flex-col gap-2 p-4 m-4 rounded-xl">
				{projects.map((project) => (
					<Link
						key={project.id}
						href={{
							pathname: '/projects/[id]',
							params: {
								id: project.id,
							},
						}}
						asChild
					>
						<TouchableOpacity className="bg-background flex flex-row gap-4 px-4 py-2 rounded-xl">
							<View className="bg-white p-1 rounded-full">
								<View
									className={`size-[50px] rounded-full overflow-hidden`}
								>
									<Image
										source={project.thumbnail}
										resizeMode="contain"
										className="w-full h-full object-center"
									/>
								</View>
							</View>
							<View className="grow flex flex-col justify-center">
								<TextBody>{project.title}</TextBody>
								<TextSub>{project.techStack.join(', ')}</TextSub>
							</View>
							<View className="flex flex-row items-center justify-center">
								<ChevronRight color={'#666d80'} />
							</View>
						</TouchableOpacity>
					</Link>
				))}
			</View>
		</ScrollView>
	);
}
