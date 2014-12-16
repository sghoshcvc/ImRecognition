function [W,H,patch] = read_im( path,imname,save2disk )
%This function reads the image stored in path,optionally it stores the
%image in binary format in the same directory.
%for real time application do not save the image.
% output im in unit8
%   

% read the image stored in path
patch = imread(fullfile(path,imname));
% prepare image for calculate integral image %
[Him,Wim,numC] = size(patch);
            if numC > 1
                patch = rgb2gray(patch);
            end
        
        
       % patch = im;%(data.words(i).loc(3):data.words(i).loc(4),data.words(i).loc(1):data.words(i).loc(2));
        
        % Move to single and equalize if necessary
        patch = im2single(patch);
        m = max(max(patch));
        if m < 0.2
            patch = patch*0.2/m;
        end
                             
        [H,W] = size(patch);
%         if (data(i).resolution.y~=H || data(i).resolution.x~=W)
%             error('something wrong happened!');
%         end
%         
%         if  (opts.minH > data(i).resolution.y)
%             patch = imresize(patch, [opts.minH,nan]);
%         end
%         if  (opts.maxH < data(i).resolution.y)
%             patch = imresize(patch, [opts.maxH,nan]);
%         end
        
        [H,W,numC] = size(patch);
        disp(H);
        disp(W);
        if save2disk
            binImname = sprintf('%s/%s',path,'tempIm.bin');
            fid = fopen(binImname,'w');
        % Save as uint8
        fwrite(fid, int32(W),'int32');
        fwrite(fid, int32(H), 'int32');
        fwrite(fid, im2uint8(patch), 'uint8');
        end
end

