import { TextDisplay } from '@/components/text';
import { View } from 'react-native';

export default function Chat() {
	return (
		<View className="w-full flex flex-row justify-center mt-4">
			<TextDisplay>Chat Bot</TextDisplay>
		</View>
	);
}
