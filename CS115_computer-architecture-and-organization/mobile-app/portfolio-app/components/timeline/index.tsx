import { cn } from '@/lib/utils';
import { View } from 'react-native';
import { TextBody, TextHeading, TextSub } from '../text';

export function TimelineContainer({
	className,
	children,
}: ComponentClassNameAndChildrenProp) {
	return (
		<View className={cn('w-[80%] [&>*]:text-center', className)}>
			{children}
		</View>
	);
}

export function TimelineHeading({
	className,
	children,
}: ComponentClassNameAndChildrenProp) {
	return (
		<TextHeading className={cn('text-center', className)}>
			{children}
		</TextHeading>
	);
}

export function TimelineSub({
	className,
	children,
}: ComponentClassNameAndChildrenProp) {
	return (
		<TextSub className={cn('text-center mt-0', className)}>{children}</TextSub>
	);
}

export function TimelineBody({
	className,
	children,
}: ComponentClassNameAndChildrenProp) {
	return (
		<TextBody className={cn('text-center mt-2', className)}>{children}</TextBody>
	);
}
