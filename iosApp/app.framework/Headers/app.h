#import <Foundation/Foundation.h>

@class AppLogLevel, AppLogLevelDEBUG, AppLogLevelINFO, AppLogLevelWARN, AppLogLevelERROR, AppCalculator, AppFibonacciCalculator, AppPartialRenderer, AppResult, AppKotlinThrowable, AppCoroutinePresenter, AppCoroutinePresenterCompanion, AppExpressionPresenter, AppKotlinArray;

@protocol AppExpressionComposer, AppFibonacciExpressionComposer, AppPartialExpressionComposer, AppBaseView, AppKotlinx_coroutines_core_nativeCoroutineScope, AppKotlinCoroutineContext, AppCalculatorView, AppCalculatorAction, AppKotlinCoroutineContextElement, AppKotlinCoroutineContextKey, AppKotlinIterator;

NS_ASSUME_NONNULL_BEGIN

@interface KotlinBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end;

@interface KotlinBase (KotlinBaseCopying) <NSCopying>
@end;

__attribute__((objc_runtime_name("KotlinMutableSet")))
__attribute__((swift_name("KotlinMutableSet")))
@interface AppMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end;

__attribute__((objc_runtime_name("KotlinMutableDictionary")))
__attribute__((swift_name("KotlinMutableDictionary")))
@interface AppMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end;

@interface NSError (NSErrorKotlinException)
@property (readonly) id _Nullable kotlinException;
@end;

__attribute__((objc_runtime_name("KotlinNumber")))
__attribute__((swift_name("KotlinNumber")))
@interface AppNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end;

__attribute__((objc_runtime_name("KotlinByte")))
__attribute__((swift_name("KotlinByte")))
@interface AppByte : AppNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end;

__attribute__((objc_runtime_name("KotlinUByte")))
__attribute__((swift_name("KotlinUByte")))
@interface AppUByte : AppNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end;

__attribute__((objc_runtime_name("KotlinShort")))
__attribute__((swift_name("KotlinShort")))
@interface AppShort : AppNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end;

__attribute__((objc_runtime_name("KotlinUShort")))
__attribute__((swift_name("KotlinUShort")))
@interface AppUShort : AppNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end;

__attribute__((objc_runtime_name("KotlinInt")))
__attribute__((swift_name("KotlinInt")))
@interface AppInt : AppNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end;

__attribute__((objc_runtime_name("KotlinUInt")))
__attribute__((swift_name("KotlinUInt")))
@interface AppUInt : AppNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end;

__attribute__((objc_runtime_name("KotlinLong")))
__attribute__((swift_name("KotlinLong")))
@interface AppLong : AppNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end;

__attribute__((objc_runtime_name("KotlinULong")))
__attribute__((swift_name("KotlinULong")))
@interface AppULong : AppNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end;

__attribute__((objc_runtime_name("KotlinFloat")))
__attribute__((swift_name("KotlinFloat")))
@interface AppFloat : AppNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end;

__attribute__((objc_runtime_name("KotlinDouble")))
__attribute__((swift_name("KotlinDouble")))
@interface AppDouble : AppNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end;

__attribute__((objc_runtime_name("KotlinBoolean")))
__attribute__((swift_name("KotlinBoolean")))
@interface AppBoolean : AppNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end;

__attribute__((swift_name("LogLevel")))
@interface AppLogLevel : KotlinBase
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LogLevel.DEBUG")))
@interface AppLogLevelDEBUG : AppLogLevel
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)dEBUG __attribute__((swift_name("init()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LogLevel.INFO")))
@interface AppLogLevelINFO : AppLogLevel
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)iNFO __attribute__((swift_name("init()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LogLevel.WARN")))
@interface AppLogLevelWARN : AppLogLevel
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)wARN __attribute__((swift_name("init()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LogLevel.ERROR")))
@interface AppLogLevelERROR : AppLogLevel
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)eRROR __attribute__((swift_name("init()")));
@end;

__attribute__((swift_name("ExpressionComposer")))
@protocol AppExpressionComposer
@required
- (id)numberValue:(double)value __attribute__((swift_name("number(value:)")));
- (id)plusLeft:(id)left right:(id)right __attribute__((swift_name("plus(left:right:)")));
- (id)minusLeft:(id)left right:(id)right __attribute__((swift_name("minus(left:right:)")));
- (id)multLeft:(id)left right:(id)right __attribute__((swift_name("mult(left:right:)")));
- (id)divLeft:(id)left right:(id)right __attribute__((swift_name("div(left:right:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Calculator")))
@interface AppCalculator : KotlinBase <AppExpressionComposer>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (AppDouble *)numberValue:(double)value __attribute__((swift_name("number(value:)")));
- (AppDouble *)plusLeft:(AppDouble *)left right:(AppDouble *)right __attribute__((swift_name("plus(left:right:)")));
- (AppDouble *)minusLeft:(AppDouble *)left right:(AppDouble *)right __attribute__((swift_name("minus(left:right:)")));
- (AppDouble *)multLeft:(AppDouble *)left right:(AppDouble *)right __attribute__((swift_name("mult(left:right:)")));
- (AppDouble *)divLeft:(AppDouble *)left right:(AppDouble *)right __attribute__((swift_name("div(left:right:)")));
@end;

__attribute__((swift_name("FibonacciExpressionComposer")))
@protocol AppFibonacciExpressionComposer <AppExpressionComposer>
@required
- (id)fibValue:(double)value __attribute__((swift_name("fib(value:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FibonacciCalculator")))
@interface AppFibonacciCalculator : KotlinBase <AppFibonacciExpressionComposer>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (AppDouble *)numberValue:(double)value __attribute__((swift_name("number(value:)")));
- (AppDouble *)plusLeft:(AppDouble *)left right:(AppDouble *)right __attribute__((swift_name("plus(left:right:)")));
- (AppDouble *)minusLeft:(AppDouble *)left right:(AppDouble *)right __attribute__((swift_name("minus(left:right:)")));
- (AppDouble *)multLeft:(AppDouble *)left right:(AppDouble *)right __attribute__((swift_name("mult(left:right:)")));
- (AppDouble *)divLeft:(AppDouble *)left right:(AppDouble *)right __attribute__((swift_name("div(left:right:)")));
- (AppDouble *)fibValue:(double)value __attribute__((swift_name("fib(value:)")));
@end;

__attribute__((swift_name("PartialExpressionComposer")))
@protocol AppPartialExpressionComposer
@required
- (id)missing __attribute__((swift_name("missing()")));
- (id)endingExpression:(id)expression __attribute__((swift_name("ending(expression:)")));
- (id)plusLeft:(id)left partialRight:(id)partialRight __attribute__((swift_name("plus(left:partialRight:)")));
- (id)minusLeft:(id)left partialRight:(id)partialRight __attribute__((swift_name("minus(left:partialRight:)")));
- (id)multLeft:(id)left partialRight:(id)partialRight __attribute__((swift_name("mult(left:partialRight:)")));
- (id)divLeft:(id)left partialRight:(id)partialRight __attribute__((swift_name("div(left:partialRight:)")));
- (id)leftParenthesizedPartialExpression:(id)partialExpression __attribute__((swift_name("leftParenthesized(partialExpression:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PartialRenderer")))
@interface AppPartialRenderer : KotlinBase <AppPartialExpressionComposer>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (NSString *)missing __attribute__((swift_name("missing()")));
- (NSString *)endingExpression:(AppDouble *)expression __attribute__((swift_name("ending(expression:)")));
- (NSString *)plusLeft:(AppDouble *)left partialRight:(NSString *)partialRight __attribute__((swift_name("plus(left:partialRight:)")));
- (NSString *)minusLeft:(AppDouble *)left partialRight:(NSString *)partialRight __attribute__((swift_name("minus(left:partialRight:)")));
- (NSString *)multLeft:(AppDouble *)left partialRight:(NSString *)partialRight __attribute__((swift_name("mult(left:partialRight:)")));
- (NSString *)divLeft:(AppDouble *)left partialRight:(NSString *)partialRight __attribute__((swift_name("div(left:partialRight:)")));
- (NSString *)leftParenthesizedPartialExpression:(NSString *)partialExpression __attribute__((swift_name("leftParenthesized(partialExpression:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Result")))
@interface AppResult : KotlinBase
- (instancetype)initWithExpression:(id _Nullable)expression partialExpression:(id)partialExpression remainder:(NSString * _Nullable)remainder __attribute__((swift_name("init(expression:partialExpression:remainder:)"))) __attribute__((objc_designated_initializer));
- (id _Nullable)component1 __attribute__((swift_name("component1()")));
- (id)component2 __attribute__((swift_name("component2()")));
- (NSString * _Nullable)component3 __attribute__((swift_name("component3()")));
- (AppResult *)doCopyExpression:(id _Nullable)expression partialExpression:(id)partialExpression remainder:(NSString * _Nullable)remainder __attribute__((swift_name("doCopy(expression:partialExpression:remainder:)")));
@property (readonly) id _Nullable expression;
@property (readonly) id partialExpression;
@property (readonly) NSString * _Nullable remainder;
@end;

__attribute__((swift_name("BaseView")))
@protocol AppBaseView
@required
- (void)showErrorT:(AppKotlinThrowable *)t __attribute__((swift_name("showError(t:)")));
@end;

__attribute__((swift_name("Kotlinx_coroutines_core_nativeCoroutineScope")))
@protocol AppKotlinx_coroutines_core_nativeCoroutineScope
@required
@property (readonly) id<AppKotlinCoroutineContext> coroutineContext;
@end;

__attribute__((swift_name("CoroutinePresenter")))
@interface AppCoroutinePresenter : KotlinBase <AppKotlinx_coroutines_core_nativeCoroutineScope>
- (instancetype)initWithMainContext:(id<AppKotlinCoroutineContext>)mainContext baseView:(id<AppBaseView>)baseView __attribute__((swift_name("init(mainContext:baseView:)"))) __attribute__((objc_designated_initializer));
- (void)onDestroy __attribute__((swift_name("onDestroy()")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CoroutinePresenter.Companion")))
@interface AppCoroutinePresenterCompanion : KotlinBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@end;

__attribute__((swift_name("CalculatorView")))
@protocol AppCalculatorView <AppBaseView>
@required
- (void)onUpdateResult:(AppDouble * _Nullable)result inputData:(NSString *)inputData __attribute__((swift_name("onUpdate(result:inputData:)")));
@property BOOL isComputing;
@end;

__attribute__((swift_name("CalculatorAction")))
@protocol AppCalculatorAction
@required
- (void)onRequestDataInputData:(NSString *)inputData __attribute__((swift_name("onRequestData(inputData:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ExpressionPresenter")))
@interface AppExpressionPresenter : AppCoroutinePresenter <AppCalculatorAction>
- (instancetype)initWithContext:(id<AppKotlinCoroutineContext>)context view:(id<AppCalculatorView>)view __attribute__((swift_name("init(context:view:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMainContext:(id<AppKotlinCoroutineContext>)mainContext baseView:(id<AppBaseView>)baseView __attribute__((swift_name("init(mainContext:baseView:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LogKt")))
@interface AppLogKt : KotlinBase
+ (void)logLevel:(AppLogLevel *)level tag:(NSString *)tag message:(NSString *)message error:(AppKotlinThrowable *)error __attribute__((swift_name("log(level:tag:message:error:)")));
+ (void)logLevel:(AppLogLevel *)level tag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("log(level:tag:message:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FibonacciParserKt")))
@interface AppFibonacciParserKt : KotlinBase
+ (AppResult *)parseAndComputeWithFibonacciExpression:(NSString *)expression __attribute__((swift_name("parseAndComputeWithFibonacci(expression:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ParserKt")))
@interface AppParserKt : KotlinBase
+ (AppResult *)parseAndComputeExpression:(NSString *)expression __attribute__((swift_name("parseAndCompute(expression:)")));
@end;

__attribute__((swift_name("KotlinThrowable")))
@interface AppKotlinThrowable : KotlinBase
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(AppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(AppKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (AppKotlinArray *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
@property (readonly) AppKotlinThrowable * _Nullable cause;
@property (readonly) NSString * _Nullable message;
@end;

__attribute__((swift_name("KotlinCoroutineContext")))
@protocol AppKotlinCoroutineContext
@required
- (id _Nullable)foldInitial:(id _Nullable)initial operation:(id _Nullable (^)(id _Nullable, id<AppKotlinCoroutineContextElement>))operation __attribute__((swift_name("fold(initial:operation:)")));
- (id<AppKotlinCoroutineContextElement> _Nullable)getKey:(id<AppKotlinCoroutineContextKey>)key __attribute__((swift_name("get(key:)")));
- (id<AppKotlinCoroutineContext>)minusKeyKey:(id<AppKotlinCoroutineContextKey>)key __attribute__((swift_name("minusKey(key:)")));
- (id<AppKotlinCoroutineContext>)plusContext:(id<AppKotlinCoroutineContext>)context __attribute__((swift_name("plus(context:)")));
@end;

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface AppKotlinArray : KotlinBase
+ (instancetype)arrayWithSize:(int32_t)size init:(id _Nullable (^)(AppInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (id _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<AppKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(id _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size;
@end;

__attribute__((swift_name("KotlinCoroutineContextElement")))
@protocol AppKotlinCoroutineContextElement <AppKotlinCoroutineContext>
@required
@property (readonly) id<AppKotlinCoroutineContextKey> key;
@end;

__attribute__((swift_name("KotlinCoroutineContextKey")))
@protocol AppKotlinCoroutineContextKey
@required
@end;

__attribute__((swift_name("KotlinIterator")))
@protocol AppKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end;

NS_ASSUME_NONNULL_END
