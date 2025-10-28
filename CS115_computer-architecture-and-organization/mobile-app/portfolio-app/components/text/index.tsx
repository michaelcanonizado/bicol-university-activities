import { cn } from '@/lib/utils';
import { Text, TextProps } from 'react-native';

type CustomTextProps = ComponentClassNameAndChildrenProp & TextProps;

export function TextDisplay({ className, children, ...props }: CustomTextProps) {
	return (
		<Text
			style={{
				fontFamily: 'Knicknack_Medium',
			}}
			className={cn(
				'text-foreground-100 text-[34px] leading-[37px] tracking-[0px]',
				className
			)}
			{...props}
		>
			{children}
		</Text>
	);
}

export function TextHeading({ className, children, ...props }: CustomTextProps) {
	return (
		<Text
			style={{
				fontFamily: 'Poppins_700Bold',
			}}
			className={cn(
				'text-foreground-100 text-[21px] leading-[24px] tracking-[0px]',
				className
			)}
			{...props}
		>
			{children}
		</Text>
	);
}

export function TextBody({ className, children, ...props }: CustomTextProps) {
	return (
		<Text
			style={{
				fontFamily: 'Poppins_400Regular',
			}}
			className={cn(
				'text-foreground-100 text-[14px] leading-[17px] tracking-[0px]',
				className
			)}
			{...props}
		>
			{children}
		</Text>
	);
}

export function TextSub({ className, children, ...props }: CustomTextProps) {
	return (
		<Text
			style={{
				fontFamily: 'Poppins_300Light',
			}}
			className={cn(
				'text-[11px] leading-[14px] tracking-[0px] text-muted-foreground',
				className
			)}
			{...props}
		>
			{children}
		</Text>
	);
}
