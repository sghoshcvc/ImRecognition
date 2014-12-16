function candidates = read_windows( )
%UNTITLED9 Summary of this function goes here
%   Detailed explanation goes here
c =0;
 fid = fopen(fullfile('model','info.txt'),'r');
    if fid>0
       
        
            text = textscan(fid,'%s %d %d %d %d %f %s');
       
        %imId = classes(['img/' nameFolds{i} '.jpg']);
        for j=1:length(text{1,1})
            %file = fullfile(path,nameFolds{i},text{1}{j});
            c = c+1;
            %candidates(c).im = rgb2gray(imread(file));
            %candidates(c).fname = text{1}{j};
            %candidates(c).imId = imId;
            candidates(c).x1 = text{2}(j);
            candidates(c).y1 = text{3}(j);
            candidates(c).w = text{4}(j);
            candidates(c).h = text{5}(j);
            candidates(c).overlap = text{6}(j);
            candidates(c).x2 = candidates(c).x1+candidates(c).w-1;
            candidates(c).y2 = candidates(c).y1+candidates(c).h-1;
            %candidates(c).imname = nameFolds{i};
            
            if strcmp(text{7}{j},'') || candidates(c).overlap<0.5
                candidates(c).gttext = '-';
            else
                candidates(c).gttext = text{7}{j};
            end
            
        end
    end
    fclose(fid);

end

