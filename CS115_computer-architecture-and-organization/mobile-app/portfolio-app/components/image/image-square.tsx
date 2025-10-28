import { cn } from '@/lib/utils';
import { Image, View } from 'react-native';

export default function ImageSquare({
	className,
	source,
}: {
	source: any;
} & ComponentClassNameProp) {
	return (
		<View className={cn('bg-white p-2  rounded-2xl overflow-hidden', className)}>
			<View className="rounded-2xl overflow-hidden size-[125px]">
				<Image source={source} className="h-full object-cover w-full" />
			</View>
		</View>
	);
}
