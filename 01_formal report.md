Week 1 : 1. Chosen model and problem and all 2. why we chose Vit over text? 1. problem of POS and context etc in text 2. Prior experience with CNNs 3. relatively more interpretable positional encodings in ViT

    3. Trained ViT, got very less accuracy

Week 2 : fixing the Vit: 1. two main problems : 1. multiple classes so too many different parameters to train

        2. vanishing gradient problem (?) (test in data)
            cause : backprop causes previous grddients to go much lowet than higher onves since its multiplied again and again

            proposed solutions :
            maybe reduce model size?
            https://chatgpt.com/share/b3efc003-42f9-4c72-ad94-6367dd405d3c

        3. Attention difficult to interpret :
            soltuions (?) :
                1.  reduced image size from tk to tk
                2. converted channels from 3 to 1

        Main proposed Improvements to current model:
            1. binary classification and BCE loss
            2. Reduce number of layers
            3. put dropout and skip connections OR change dataset to get dataset with more samples OR change architecture totally (Resnet etc)
            ![alt text](image.png)

        If that doesnt work:
        BUZZWORD : PRETRAIN !


            1.  Google/Read out how to train a dataset with less training samples
                https://www.reddit.com/r/MachineLearning/comments/1av70eo/d_how_to_train_vit_vs_cnn/

                some quotes (unverified) (?):
                    1. 'More data. VIT's scales better with larger datasets, but tend not to do well with smaller datasets. My rule of thumb is greater than 100k "samples" and you are getting into VIT dataset size.'

                    2.




            other ideas :
                1. transfer learning : train a CNN first on the data then use weights for Vit
                2. fine tuning sttrats like LORA etc (see reddit thread)
                2. find pretrained weights, example imagenet etc (see the reddit thread above)
                    eg simplest thing to do would be to use a pre trained vit network and then fine tune it on the new dataset by changing the classification head

            2.Find a dataset with more training examples, on which ViT can be trained


        To convert from

Week 3 :
Started analysis of image:
proposed resoirce :
https://viso.ai/deep-learning/vision-transformer-vit/#:~:text=Particularly%2C%20if%20the%20ViT%20model,the%20process%20of%20fine%2Dtuning
