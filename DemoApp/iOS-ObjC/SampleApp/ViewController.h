//
//  ViewController.h
//  SampleTestApp
//
//  Created by Nirvaid Rathore on 10/03/16.
//  Copyright © 2016 Nirvaid Rathore. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController<UITextFieldDelegate>

- (IBAction)initSDKClicked:(id)sender;
- (IBAction)cleanupSDKClicked:(id)sender;
- (IBAction)createSessionClicked:(id)sender;
- (IBAction)reportErrorClicked:(id)sender;
- (IBAction)cleanupSessionClicked:(id)sender;
- (IBAction)updateMetaDataClicked:(id)sender;
- (IBAction)sendEventClicked:(id)sender;
@property (weak, nonatomic) IBOutlet UISegmentedControl *adSegment;
@property(weak,nonatomic)IBOutlet UITextField *customerKeyTextField;

@end

