import { cn } from '@/lib/utils';
import { Image, View } from 'react-native';

export default function ImageCircle({
	className,
	source,
}: {
	source: any;
} & ComponentClassNameProp) {
	return (
		<View
			className={cn(
				'bg-white p-2 w-fit h-fit rounded-full overflow-hidden',
				className
			)}
		>
			<View className="rounded-full overflow-hidden size-[100px]">
				<Image source={source} className="h-full object-cover w-full" />
			</View>
		</View>
	);
}
