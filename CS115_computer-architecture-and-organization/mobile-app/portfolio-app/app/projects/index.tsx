import { TextBody, TextSub } from '@/components/text';
import { Link } from 'expo-router';
import { Image, ScrollView, TouchableOpacity, View } from 'react-native';
import ChevronRight from '../../assets/images/chevron-right.svg';

export type Project = {
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
		title: 'React Movies🎬',
		year: 2023,
		techStack: ['ReactJS', 'TailwindCSS', 'Redux'],
		type: 'Frontend',
		description:
			'Developed as a freshman project, this movie database web app shows detailed movie information, ratings, and trailers, providing users with comprehensive movie information powered by TMDB API',
		link: 'https://michaelcanonizado.github.io/react-movies-website/#/popular',
		images: [
			require('../../assets/projects/react-movies-1.jpg'),
			require('../../assets/projects/react-movies-2.jpg'),
			require('../../assets/projects/react-movies-3.jpg'),
		],
		thumbnail: require('../../assets/projects/react-movies-3.jpg'),
	},
	{
		title: 'RSA Cipher Tool',
		year: 2023,
		techStack: ['C'],
		type: 'Low Level',
		description:
			'The RSA Cipher Tool is a C-based encryption utility that implements the RSA (Rivest–Shamir–Adleman) algorithm to generate keys, encrypt, and decrypt data. Developed as a freshman Computer Science capstone project for Computer Programming 2, it showcases a deep dive into cryptography and number theory. To overcome the limitations of C’s native data types, we built a custom high-precision arithmetic library (bignum.h) from scratch.',
		link: 'https://github.com/michaelcanonizado/rsa-cipher-tool',
		images: [
			require('../../assets/projects/rsa-cipher-tool-1.jpg'),
			require('../../assets/projects/rsa-cipher-tool-2.jpg'),
			require('../../assets/projects/rsa-cipher-tool-3.jpg'),
		],
		thumbnail: require('../../assets/projects/rsa-cipher-tool-1.jpg'),
	},
	{
		title: 'Minder💸',
		year: 2024,
		techStack: ['NextJS', 'TailwindCSS', 'MongoDB'],
		type: 'Fullstack',
		description:
			'Due to my lack of knowledge in Excel, I created a personal finance tracker. Since I am more skilled in web development, I created a website that tracks my finances and provides analytics.',
		link: 'https://github.com/michaelcanonizado/minder',
		images: [
			require('../../assets/projects/minder-2.jpg'),
			require('../../assets/projects/minder-1.jpg'),
			require('../../assets/projects/minder-1.jpg'),
		],
		thumbnail: require('../../assets/projects/minder-1.jpg'),
	},
	{
		title: 'Markup',
		year: 2024,
		techStack: ['Java'],
		type: 'Language',
		description:
			'Markup is a custom Markdown-inspired language built as a project for CS112 (Programming Languages). Designed and implemented from scratch, it features its own grammar and a fully functional parser. Markup supports escape sequences for text formatting, nested styles, and efficient recursive descent parsing, all accessible through an interactive GUI.',
		link: 'https://github.com/michaelcanonizado/markup',
		images: [
			require('../../assets/projects/markup-2.jpg'),
			require('../../assets/projects/markup-1.jpg'),
			require('../../assets/projects/markup-3.jpg'),
		],
		thumbnail: require('../../assets/projects/markup-1.jpg'),
	},
	{
		title: 'BU Tabulation',
		year: 2025,
		techStack: ['ReactJS', 'Spring Boot', 'PostgrSQL'],
		type: 'Fullstack',
		description:
			'BU Tabulation is an offline pageant tabulation system built to handle real-time scoring, computation, and result management for multiple pageants across Bicol University. Designed for reliability and performance, it’s primarily used by the university-wide pageant: Mr. and Ms. Bicol University (MMBU). It includes an admin dashboard with live score updates, contestant leaderboards, plus a dynamic formula engine for customizable award computations.',
		link: 'https://github.com/buGDG-collab/BU-Tabulation-System',
		images: [
			require('../../assets/projects/bu-tabulation-1.jpg'),
			require('../../assets/projects/bu-tabulation-2.jpg'),
			require('../../assets/projects/bu-tabulation-3.jpg'),
		],
		thumbnail: require('../../assets/projects/bu-tabulation-1.jpg'),
	},
];

export default function ProjectsList() {
	return (
		<ScrollView className="bg-background flex flex-col gap-4">
			<View className="bg-muted flex flex-col gap-2 p-4 m-4 rounded-xl">
				{projects.map((project) => (
					<Link
						key={project.title}
						href={{
							pathname: '/projects/[id]',
							params: {
								titleId: project.title,
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
										resizeMode="cover"
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
