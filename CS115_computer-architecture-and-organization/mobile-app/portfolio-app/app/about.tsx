import { TextBody, TextDisplay, TextHeading, TextSub } from '@/components/text';
import { ScrollView, View } from 'react-native';

export default function About() {
	return (
		<ScrollView contentContainerClassName="flex flex-col gap-4 grow items-center justify-center bg-background p-4">
			<View className="flex flex-col gap-2 items-center w-[80%] mb-4">
				<TextDisplay className="text-center">Typography Sheet</TextDisplay>
				<TextBody className="text-center">
					Lorem ipsum blah blah blah long text. Look at my projects!
				</TextBody>
			</View>
			<View className="flex flex-row gap-2 mb-4">
				<View className="p-2 bg-white rounded-2xl">
					<View className="bg-accent-orange size-[120px] aspect-square rounded-xl" />
				</View>
				<View className="p-2 bg-white rounded-2xl">
					<View className="bg-accent-green size-[120px] aspect-square rounded-xl" />
				</View>
				<View className="p-2 bg-white rounded-2xl">
					<View className="bg-accent-blue size-[120px] aspect-square rounded-xl" />
				</View>
			</View>
			<View className="flex flex-col gap-2 bg-muted rounded-3xl  p-4">
				<View className="flex flex-row gap-1">
					<TextHeading className="text-background">•</TextHeading>
					<TextHeading className="">Projects</TextHeading>
				</View>
				<View className=" w-full flex flex-col gap-4">
					<View className="flex flex-row gap-2 bg-background p-2 rounded-2xl">
						<View className="size-[35px] rounded-full bg-accent-orange" />
						<View className="flex flex-col justify-between">
							<TextBody>Linux Kernel</TextBody>
							<TextSub>Project description will be shown here</TextSub>
						</View>
					</View>
					<View className="flex flex-row gap-2 bg-background p-2 rounded-2xl">
						<View className="size-[35px] rounded-full bg-accent-green" />
						<View className="flex flex-col justify-between">
							<TextBody>ChatGPT 6</TextBody>
							<TextSub>Project description will be shown here</TextSub>
						</View>
					</View>
					<View className="flex flex-row gap-2 bg-background p-2 rounded-2xl">
						<View className="size-[35px] rounded-full bg-accent-blue" />
						<View className="flex flex-col justify-between">
							<TextBody>BULMS</TextBody>
							<TextSub>Project description will be shown here</TextSub>
						</View>
					</View>
				</View>
			</View>
			<View className="rounded-full bg-accent-yellow px-8 pt-4 pb-3">
				<TextHeading
					style={{ fontFamily: 'Knicknack_Medium' }}
					className="text-background"
				>
					+ Add me on Guthib
				</TextHeading>
			</View>
		</ScrollView>
	);
}
